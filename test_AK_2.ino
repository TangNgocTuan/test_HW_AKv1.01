#include "test.h"
void setup() {
  // put your setup code here, to run once:
  initPort();
  testSerial();
  startPort();
  testWifi();
  testSim();
}

void loop() {
  // put your main code here, to run repeatedly:
//  startPort();
  testPower();
}
