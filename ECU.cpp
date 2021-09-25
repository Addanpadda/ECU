#include "ECU.hpp"

ECU::ECU() {
  Serial.begin(9600);
  rpm = new RPM();

  delay(1000);
}

void ECU::loop() {
  rpm->calcRPM();
  Serial.println(rpm->average);
}
