#include <Arduino.h>
#include "MAF.hpp"
#include "Constants.hpp"

int MAF::get() {
  double voltage = (analogRead(MAF_PIN)/1023)*5;

  return mapValue(voltage);
}

unsigned int MAF::mapValue(float voltage) {
  const int lowerIndex = (int)(voltage*Constants::MAF::valuesPerVolt);
  const int upperIndex = lowerIndex+1;
  const float offsetFromLower = (voltage*(float)Constants::MAF::valuesPerVolt) - (int)(voltage*(float)Constants::MAF::valuesPerVolt);

  return Constants::MAF::Values[lowerIndex] * (1-offsetFromLower) + Constants::MAF::Values[upperIndex] * offsetFromLower;
}
