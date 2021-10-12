#include <Arduino.h>
#include "MAF.hpp"
#include "Constants.hpp"
#include "Settings.hpp"

MAF::MAF(int pin) {
  _pin = pin;
}

int MAF::get() {
  double voltage = (analogRead(_pin)/1023.0)*5.0;

  return mapValue(voltage);
}

unsigned int MAF::mapValue(float voltage) {
  const int lowerIndex = (int)(voltage*Constants::MAF::valuesPerVolt);
  const int upperIndex = lowerIndex+1;
  const float offsetFromLower = (voltage*(float)Constants::MAF::valuesPerVolt) - (int)(voltage*(float)Constants::MAF::valuesPerVolt);

  return Constants::MAF::Values[lowerIndex] * (1-offsetFromLower) + Constants::MAF::Values[upperIndex] * offsetFromLower;
}
