boolean Relay_1 = false; // to remember state of relay 1, false = off, true = on
boolean Relay_2 = false; // to remember state of relay 2, false = off, true = on

void setup() {
  Serial.begin(19200);
}

void turnON(byte relayID) {
  if (relayID==1) Relay_1 = true;
  if (relayID==2) Relay_2 = true;
  setRelay(Relay_1,Relay_2); 
}

void turnOFF(byte relayID) {
  if (relayID==1) Relay_1 = false;
  if (relayID==2) Relay_2 = false;
  setRelay(Relay_1,Relay_2);
}

void turnBothON() {
  Relay_1 = true;
  Relay_2 = true;
  setRelay(Relay_1,Relay_2);
}

void turnBothOFF() {
  Relay_1 = false;
  Relay_2 = false;
  setRelay(Relay_1,Relay_2);
}

void setRelay (boolean r1, boolean r2) {
  byte address = 0;
  if (r1) address++;
  if (r2) address += 2;
  Serial.write(0xA0);
  Serial.write(0x04);
  Serial.write(address);
  Serial.write(0xA1);
  Serial.flush();  
}

void loop() {
   
   // Unit test
   turnON(1);
   delay(1000);
   turnON(2);
   delay(1000);
   turnOFF(1);
   delay(1000);
   turnOFF(2);
   delay(1000);
   turnBothON();
   delay(1000);
   turnBothOFF();
   delay(1000);
   turnBothON();
   delay(1000);
   turnOFF(1);
   delay(1000);
   turnBothON();
   delay(1000);
   turnOFF(2);
   delay(1000);
   turnBothOFF();
   delay(1000); 
}
