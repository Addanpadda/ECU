#include "ECU.hpp"

ECU *ecu;

void setup() {
  ecu = new ECU();
  delay(1000);
}

void loop() {
  ecu->loop();
}
