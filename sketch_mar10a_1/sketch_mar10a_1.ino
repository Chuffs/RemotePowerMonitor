/**
 * Orig. Author:   Matthew Law - mljl.tech
 * Created:        March 2022 
 * 
 * Power Outage detection and notification for a remote site
 * 
 * Using Waveshare SIM7000E GPRS and GPS Module through serial connection
 * https://www.waveshare.com/sim7000e-nb-iot-hat.htm
 * https://escapequotes.net/esp8266-wemos-d1-mini-pins-and-diagram/  
 * 
 * 
 * Serial Connection Config:
 *    UART0 to receive Data from SIM Module
 *        D7 pin or GPIO 13
 *    UART1 to send Data to SIM Module 
 *        D4 pin or GPIO 2  
 * 
 */

//boolean function if command sent to module *should* return an OK status
bool sendCommandOK(String command);
//boolean function if command sent to module returns anything other than OK;
//and the returned status is not needed
bool sendCommandOther(String command, char* expected); 
//String funtion to return the status or info from the module
String sendCommand(String command);
//Function to retry command until an OK status is recieved
void waitForOK(String commmand);
//Function to send SMS message to specified number - no checks
void sendSMS_OK(String message, String number);

//Phone number w/ area code, e.g. Australia = +61
String phonenumber = "+61449001120";

void setup() {
  int signalFlag = 1;
  String signalStr;
  int signalResponse[2];

  Serial.begin(9600);
  while(!Serial);
  Serial.swap();
  Serial.println("Serial Ready!");
  
  Serial1.begin(9600);
  while(!Serial1);
  Serial.println("Serial1 Ready!");

  // Attention Device
  sendCommand("AT");
  //See if device is ready & ensure echo is off
  waitForOK("ATE0");
  //Disable Timezone Reporting
  waitForOK("AT+CLTS=0");
  //Enable LTE Mode for SIM
  waitForOK("AT+CNMP=38");
  //Enable CAT-M1 and nb-IoT
  waitForOK("AT+CMNB=3");
  //Enable reporting of network registration status
  waitForOK("AT+CREG=1");
  //Automatically select network operator
  waitForOK("AT+COPS=0");
  //SMS Text Mode
  waitForOK("AT+CMGF=1");
  
  //Check signal
  while(1) {
    signalStr = sendCommand("AT+CREG?");
  //Response will be +CREG:x,x - remove +CREG: so we are left with valuable info
    signalStr = signalStr.substring(7, signalStr.length()-8);

  //Convert from ASCII to decimal numbers
    signalResponse[0] = (int)signalStr[0] - 48;
    signalResponse[1] = (int)signalStr[2] - 48;
    
    if(signalResponse[0] == 1) {
      if(signalResponse[1] == 1 | signalResponse[1] == 5){
        Serial.println("Connected to a Network");
        break;
      }
    } else {
      Serial.println("Command OK, not connected to Network");
    }
    delay(5000);
  }

  Serial.println("Setup Complete, Config valid.");
}

void loop() {
  if(analogRead(A0) < 500){
    delay(1000);
    if(analogRead(A0) < 500) {
      // Send SMS for power outage
      Serial.println("Power Outage Detected");

      sendSMS_OK("Power Outage at Location: @A", phonenumber);
      
      while(analogRead(A0) < 500){
        delay(100);
      }
      // Power Restored
      Serial.println("Power Restored");
      sendSMS_OK("Power Restored at Location: @A", phonenumber);
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
  Serial.print("Command Sent: ");
  Serial.println(command);

  delay(500);
  while(Serial.available() > 0) {
    incomingChar = Serial.read();
    response.concat(incomingChar);
  }

//Check to see if we actually got anything from Serial
  if(response == ""){
    Serial.println("No Response");
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
    //Usually paired with waitForOK subroutine, so will try again in 5 seconds
    return false;
  }

}

bool sendCommandOK(String command, char* expected) {
  int incomingByte = 0;
  String response;
  char incomingChar;

//Send command to module on Serial1, repeat command to debug on Serial
  Serial1.println(command);
  Serial.print("Command Sent: ");
  Serial.println(command);

  delay(500);
  while(Serial.available() > 0) {
    incomingChar = Serial.read();
    response.concat(incomingChar);
  }

//Check to see if we actually got anything from Serial
  if(response == ""){
    Serial.println("No Response");
    Serial.println(response);
    return false;
  }

//Remove \r and \n from from begining of response and \n from ending
  response = response.substring(2,response.length()-1);

//  For debug purposes, print ASCII code of chars in response
  for(int i = 0; i < response.length(); i++) {
    Serial.print(response[i],DEC);
    Serial.print(",");
  }

  if(response == expected) {
    Serial.print(" - Success!\n");
    return true;
  } else {
    Serial.print(" - FAIL\n");
    //Usually paired with waitForOK subroutine, so will try again in 5 seconds
    return false;
  }

}

String sendCommand(String command) {
  String response;
  char incomingChar;
  char error[8] = {'E','R','R','O','R','\r','\n','\0'};

  Serial1.println(command);
  Serial.print("Command Sent: ");
  Serial.println(command);

  delay(500);
  while(Serial.available()) {
    incomingChar = Serial.read();
    response.concat(incomingChar);
  }

  if(response == ""){
    Serial.println("No Response");
    return "Error";
  }

  response = response.substring(2,response.length());

  if(response == error) {
    Serial.print("Invalid response: ");
    Serial.println(response);
  } else {
    Serial.print(response.substring(0, response.length()-1));
    Serial.println(" - Success!");
  }
  
  return response;
}

void waitForOK(String command) {
  int delay_val = 1000;
  while(1) {
    if(sendCommandOK(command)){
      // Recieved correct data from SIM Module, return
      return;
    } else {
      // Nothing returned from SIM Module, try again
      Serial.printf("No response from module, trying again in %d seconds\n", delay_val/1000);
      delay(delay_val);
      delay_val <= 10000 ? delay_val : delay_val * 2; 
    }
  }
}

void sendSMS_OK(String message, String number) {
  char CTRL_Z = '';
  String command;
  String response;
  int incomingChar;
  
  command = String("AT+CMGS=\"") + number + String("\"");
  Serial1.println(command);
  Serial.print("Command sent: ");
  Serial.println(command); 

  delay(500);
  Serial1.print(message);
  Serial1.print(CTRL_Z);
}
