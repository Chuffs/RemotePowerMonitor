int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Serial Ready!");
  
  Serial1.begin(9600);
  while(!Serial1);
  Serial.println("Serial1 Ready!");
}

bool flag = 1;

bool sendCommand(char command);

void loop() {
  while(flag) {
    Serial1.println("AT");
    Serial.println("AT");
    delay(5000);
    while(Serial.available() > 0) {
      incomingByte = Serial.read();
      Serial.print((char)incomingByte);
    }
  }
}
