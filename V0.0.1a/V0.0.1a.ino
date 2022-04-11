/* Created my Matthew Law - 2022 - mljl.tech
* Connections - 
 *    D0 - TX, GPIO16
*    D6 - RX, GPIO14
*    A0 - Monitor, ADC0
*    Transmit on Serial1, Recieve on Serial0
*/

#include <SoftwareSerial.h>

#define D0 16
#define D6 14

SoftwareSerial modem(D0, D6); // RX, TX

int incomingByte = 0;

void setup() {
  Serial.begin(74880);
  while(!Serial);
  Serial.println("Serial Ready!");

  modem.begin(9600);
  while(!modem);
  Serial.println("Modem Serial Ready!");

}

void loop() {
  if(analogRead(A0) < 500){
    delay(1000);
    if(analogRead(A0) < 500) {
      // Send SMS for power outage
      Serial.println("Power Outage Detected");
      
      while(analogRead(A0) < 500){
        delay(100);
      }
      // Power Restored
      Serial.println("Power Restored");
    }    
  }
  if(Serial.available() > 0 ) {
    incomingByte = Serial.read();
    Serial.print((char)incomingByte);
    modem.print((char)incomingByte);
  }
}
