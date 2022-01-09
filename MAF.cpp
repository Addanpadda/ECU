#include <Arduino.h>
#include "MAF.hpp"
#include "Constants.hpp"
#include "Settings.hpp"
#include "Utils.hpp"

MAF::MAF(int pin) {
  _pin = pin;
  graph = new Graph<float, int>(Constants::MAF::voltageValues, Constants::MAF::airFlowValues, Constants::MAF::size);
}

int MAF::get() {
  double voltage = (analogRead(_pin)/1023.0)*5.0;
  voltage += (analogRead(_pin)/1023.0)*5.0;
  voltage /= 2; // Average voltage

  return mapValue(voltage);
}

unsigned int MAF::mapValue(float voltage) {
  return graph->getY(voltage);
}
