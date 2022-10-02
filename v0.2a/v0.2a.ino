/*  Orig. Author:   Matthew Law - mljl.tech
 *  Created:        March 2022
 *  
 *  Power Outage detection and notification for a remote site
 *  
 *  ESP8266 Wemos Mini D1 -
 *  https://escapequotes.net/esp8266-wemos-d1-mini-pins-and-diagram/
 *  Using Waveshare SIM7000E GPRS and GPS Module through serial connection -
 *  https://www.waveshare.com/sim7000e-nb-iot-hat.htm
 *  
 *  Serial Connection Config:
 *      UART0 to receive Data from SIM Module
 *          D7 pin or GPIO 13 (3RHS)
 *      UART1 to send Data to SIM Module 
 *          D4 pin or GPIO 2  (3LHS)
 *   
 *   Includes modifications from the following examples:
 *      https://roboticsbackend.com/arduino-write-string-in-eeprom/
 *      https://microcontrollerslab.com/esp32-esp8266-web-server-input-data-html-forms/
 *      https://forum.arduino.cc/t/esp8266-getresetreason-wrong-result/424689
 *      
 *      Reset Codes:
 *      Code 4 -> Software restart
 *      Code 5 -> Wake from deepSleep
 *      Code 6 -> External Reset - use this to put device into config mode
 * 
 */

#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncTCP.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>

#include <stdio.h>

#define SENSORPIN 14
#define normalDelay 300e6 //5 minutes
#define outageDelay 300e6 //5 minutes

#include <EEPROM.h>

AsyncWebServer server(80);

const char* APSSID = "ESP";

//String funtion to return the status or info from the module
String sendCommand(String command);
//Bool function to check config of Modem is valid & modem is connected to network
bool configModemCheck();
//Function to retry command until an OK status is recieved
void waitForOK(String commmand);
//boolean function if command sent to module *should* return an OK status
bool sendCommandOK(String command);
//Send SMS Payload
void sendSMS(String emailAdd, String loc, float v, String pstat);

float mapf(float x, float in_min, float in_max, float out_min, float out_max);

IPAddress staticIP(192, 168 ,0, 4);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

const char* input_parameter1 = "email";
const char* input_parameter2 = "location";

String email, location;

unsigned long previousMillis = 0;
const long interval = 3e5;
//Hologram Cloud API SMS Number
String phonenumber = "447937405250";

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>Power Outage Detection Config</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {font-family: Times New Roman; display: inline-block; text-align: center;}
    h2 {font-size: 3.0rem; color: black;}
  </style>
  </head><body>
  <h1>Power Outage Detection Config</h1> 
  <form action="/get">
    Email to notify: <input type="text" name="email">
    <input type="submit" value="Submit">
  </form><br>
  <form action="/get">
    Current Location: <input type="text" name="location">
    <input type="submit" value="Submit">
  </form><br>
</body></html>)rawliteral";

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void writeStringToEEPROM(int addrOffset, const String &strToWrite) {
  byte len = strToWrite.length();
  EEPROM.write(addrOffset, len);
  EEPROM.commit();
  for (int i = 0; i < len; i++)
  {
    EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
    if (EEPROM.commit()) {
      Serial.println("EEPROM successfully committed");
    } else {
      Serial.println("ERROR! EEPROM commit failed");
    }
  }
}

String readStringFromEEPROM(int addrOffset) {
  int newStrLen = EEPROM.read(addrOffset);
  char data[newStrLen + 1];
  for (int i = 0; i < newStrLen; i++)
  {
    data[i] = EEPROM.read(addrOffset + 1 + i);
  }
  data[newStrLen] = '\0';
  return String(data);
}



void WiFiStart() {
  Serial.print("Setting AP Config: ");
  Serial.println(WiFi.softAPConfig(staticIP, gateway, subnet) ? "Ready!" : "Failed!");

  Serial.print("Setting AP SSID: ");
  Serial.println(WiFi.softAP(APSSID) ? "Ready" : "Failed!");

  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
  
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
  //Email
    if (request->hasParam(input_parameter1)) {
      email = request->getParam(input_parameter1)->value();
      writeStringToEEPROM(0, email);
    }
  //Location
    else if (request->hasParam(input_parameter2)) {
      location = request->getParam(input_parameter2)->value();
      writeStringToEEPROM(128, location);
    }
    
    request->send(200, "text/html", "Updated!<br><a href=\"/\">Return</a>");
  });
  server.onNotFound(notFound);
  server.begin();
}

void modemStart() {
  //Attention Device and ensure echo is off
  waitForOK("ATE0");
  //Disable Timezone Reporting
  waitForOK("AT+CLTS=0");
  //Enable LTE Mode for SIM
  waitForOK("AT+CNMP=38");
  //Enable CAT-M1 and nb-IoT
  waitForOK("AT+CMNB=1");
  //Enable reporting of network registration status
  waitForOK("AT+CREG=1");
  //Automatically select network operator
  waitForOK("AT+COPS=0");
  //SMS Text Mode
  waitForOK("AT+CMGF=1");
}

void sendPayload(String emailAdd, String loc, float v, String pstat){
  Serial.print("\r###DEBUG: ");
  Serial1.print("{\"email\":\"");
  Serial.print("{\"email\":\"");
  Serial1.print(emailAdd);
  Serial.print(emailAdd);
  Serial1.print("\",\"location\":\"");
  Serial.print("\",\"location\":\"");
  Serial1.print(loc);
  Serial.print(loc);
  Serial1.print("\",\"battery\":\"");
  Serial.print("\",\"battery\":\"");
  Serial1.print(v);
  Serial.print(v);
  Serial1.print("\",\"power_status\":\"");
  Serial.print("\",\"power_status\":\"");
  Serial1.print(pstat);
  Serial.print(pstat);
  Serial1.print("\"}\n\r");
  Serial.print("\"}\n");
}

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.swap();
  Serial.println("Serial Ready!");

  Serial1.begin(9600);
  while(!Serial1);
  Serial.println("Serial 1 Ready!");
  
  EEPROM.begin(512);

  pinMode(SENSORPIN, INPUT);

  rst_info *resetInfo;
  resetInfo = ESP.getResetInfoPtr();

  Serial.print("Reset Code = ");
  Serial.println(resetInfo->reason);

  if(resetInfo->reason == 6) {
    bool flag = true;
    WiFiStart();    
    } else if (resetInfo->reason == 4) {
    modemStart();
  }

  email = readStringFromEEPROM(0);
  location = readStringFromEEPROM(128);
  String configDetails = "Email address to notify: " + email + ", reporting Location as: " + location + ".";
  Serial.println(configDetails);

  delay(500);

  modemStart();

//  while(1) {
//    bool flag = configModemCheck();
//    delay(500);
//    Serial.print("Checking Modem Config: ");
//    if(!flag) {
//      modemStart();
//    } else {
//      break;
//    }
//  }
}

void loop() {
  // What is the current battery level?
  float vbat = mapf(analogRead(A0)*2, 0, 1024, 0, 3.2);
  delay(500);
  Serial.print("Current Detection Voltage = ");
  Serial.println(vbat);
  // if battery is ~3.5, battery is running low, notify user
  if(vbat <= 3.50) {
    //Send SMS
    sendSMS(email, location, vbat, "normal");
  }
  delay(500);
  Serial.print("Checking Power Status: ");
  Serial.println(digitalRead(SENSORPIN) ? "Normal" : "Outage");
  // Check IR Sensor/DC Power
  if(digitalRead(SENSORPIN) == false ) {
    //Power Outage
    Serial.println("###DEBUG: POWER OUTAGE DETECTED");
    //Send SMS
    //Construct Payload
    // void sendSMS(String emailAdd, String loc, float v, String pstat);
    sendSMS(email, location, vbat, "Outage");
    bool powerOut = true;
    while(powerOut) {
      delay(500); //Every 5 minutes
      powerOut = digitalRead(SENSORPIN) ? false : true;
    }
    //If we get here, power has been restored
    Serial.println("###DEBUG: POWER RESTORED");
    //Send SMS
    sendSMS(email, location, vbat, "Restored");
  } else {
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      ESP.deepSleep(normalDelay);
    }
    yield();
  }
}

String sendCommand(String command) {
  String response;
  char incomingChar;
  char error[8] = {'E','R','R','O','R','\r','\n','\0'};
  
  delay(500);
  Serial1.println(command);
  Serial.print("\rCommand Sent: ");
  Serial.println(command);

  delay(500);
  while(Serial.available()) {
    incomingChar = Serial.read();
    response.concat(incomingChar);
    Serial.print(incomingChar,DEC);
    Serial.print(",");
  }

  if(response == ""){
    Serial.println("No Response");
    return String("Error");
  }

  response = response.substring(2,response.length());
  
  return response;
}

bool configModemCheck() {
  String signalStr;
  int signalResponse[2];

  signalStr = sendCommand("AT+CREG?\n\r");

  delay(500);
  Serial.println(signalStr);
  
  //Response will be +CREG:x,x - remove +CREG: so we are left with valuable info
  signalStr = signalStr.substring(7, signalStr.length()-8);

  //Convert from ASCII to decimal numbers
  signalResponse[0] = (int)signalStr[0] - 48;
  signalResponse[1] = (int)signalStr[2] - 48;

  //DEBUG
  Serial.print("\nsignalResponse[0] = ");
  Serial.println(signalResponse[0]);
  Serial.print("signalResponse[1] = ");
  Serial.println(signalResponse[1]);
  
  //Check if modem is connected to Home network or is roaming
  if(signalResponse[1] == 1 | signalResponse[1] == 5) {
    Serial.println("Connected to a Network - SMS Opperational");
    return true;
  } else if(signalResponse[1] == 0) {
    Serial.println("Modem not searching for new network, reset device...");
    ESP.restart();
  } else if(signalResponse[1] == 2) {
    Serial.println("Modem still searching for network to attach to, sleeping...");
    ESP.deepSleep(60e6);
  } else {
    Serial.println("No Response");
    return false;
  }
}

void waitForOK(String command) {
  int delay_val = 1;
  int cmd_sent = 1;
  while(cmd_sent) {
    if(sendCommandOK(command)){
      // Recieved correct data from SIM Module
      cmd_sent = 0;
      return;
    } else {
      // Nothing returned from SIM Module, try again
      Serial.printf(" from module, trying again in %d seconds\n", delay_val);
    if(delay_val < 10) {
      delay_val++;
    }
    delay(delay_val*1000);
    }
  }
}

bool sendCommandOK(String command) {
  int incomingByte = 0;
  String response;
  char expected[5] = {'O', 'K', '\r', '\n', '\0'};
  char incomingChar;

//Send command to module on Serial1, repeat command to debug on Serial
  Serial1.println(command);
  Serial.print("\rCommand Sent: ");
  Serial.println(command);

  delay(500);
  while(Serial.available() > 0) {
    incomingChar = Serial.read();
    response.concat(incomingChar);
  }

//Check to see if we actually got anything from Serial
  if(response == ""){
    Serial.print("No Response");
//    Serial.println(response);
    return false;
  }

//Remove \r and \n from from begining of response
  response = response.substring(2,response.length());

//  For debug purposes, print ASCII code of chars in response
  for(int i = 0; i < response.length(); i++) {
    Serial.print(response[i],DEC);
    Serial.print(",");
  }
  Serial.print(response);

  if(response == expected) {
    Serial.print(" - Success!\n");
    return true;
  } else {
    Serial.print(" - FAIL\n");
    //Usually paired with waitForOK subroutine, so will try again in 1-10 seconds
    return false;
  }
}


void sendSMS(String emailAdd, String loc, float v, String pstat) {
  char CTRL_Z = '';
  String command;
  String response;
  int incomingChar;

  //String phonenumber = "447937405250";
  Serial1.println("AT+CMGS=\"447937405250\"\n\r");
  Serial.print("Command sent: AT+CMGS=\"447937405250\"\n\r");

  delay(500);

  Serial.print("\r###DEBUG: ");
  Serial1.print("{\"email\":\"");
  Serial.print("{\"email\":\"");
  Serial1.print(emailAdd);
  Serial.print(emailAdd);
  Serial1.print("\",\"location\":\"");
  Serial.print("\",\"location\":\"");
  Serial1.print(loc);
  Serial.print(loc);
  Serial1.print("\",\"battery\":\"");
  Serial.print("\",\"battery\":\"");
  Serial1.print(v);
  Serial.print(v);
  Serial1.print("\",\"power_status\":\"");
  Serial.print("\",\"power_status\":\"");
  Serial1.print(pstat);
  Serial.print(pstat);
  Serial1.print("\"}\n\r");
  Serial.print("\"}\n");

  Serial1.print((char)26);
  Serial1.print("\n\r");

  Serial.println((char)26);

  return;
}

float mapf(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
