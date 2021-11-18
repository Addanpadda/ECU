#include "ECU.hpp"

ECU *ecu;

void setup() {
  ecu = new ECU();
}

void loop() {
  ecu->loop();
}
