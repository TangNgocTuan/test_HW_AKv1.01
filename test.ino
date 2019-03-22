#include "test.h"

void initPort() {
  pinMode(ERR, OUTPUT);
  pinMode(SIM, OUTPUT);
  pinMode(EMR, OUTPUT);
  pinMode(PWR, OUTPUT);
  digitalWrite(EMR,Lo);
  digitalWrite(PWR,Hi);
  pinMode(WIFI, OUTPUT);
  pinMode(Vsys, INPUT_PULLUP);
  pinMode(Vctrl, OUTPUT);
  digitalWrite(Vctrl,Hi);
}
void testSerial() {
  digitalWrite(ERR, Hi);
  delay(1000);
  Serial.begin(BAUD);
  while (!Serial);
  Serial.println("Serial started!");
  digitalWrite(ERR, Lo);
}
void startPort() {
  digitalWrite(ERR, Hi);
  digitalWrite(SIM, Hi);
  digitalWrite(WIFI, Hi);
  delay(1000);
  digitalWrite(ERR, Lo);
  digitalWrite(SIM, Lo);
  digitalWrite(WIFI, Lo);
  delay(1000);
}

void testWifi() {
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    digitalWrite(WIFI, digitalRead(WIFI) ^ 0x01);
  }
  digitalWrite(WIFI, Hi);
}

void testSim() {
  SIM808_Setup();
  while (SIMData_Read(1) == 0) {
    delay(3000);
    digitalWrite(SIM, digitalRead(SIM) ^ 0x01);
  }
  if (SIMData_Read(1)) {
    digitalWrite(SIM, Hi);
  }
}

void testPower() {
//  Serial.print("Vsys : ");
//  Serial.println(analogRead(Vsys));
//  if (analogRead(Vsys) > 4100) {
//    digitalWrite(ERR, 1);
//  }
//
//  else {
//    digitalWrite(ERR, 0);
//  }
//  Serial.println(digitalRead(Vsys));
  digitalWrite(ERR, digitalRead(Vsys));
//  delay(2000);
}



