#include <Arduino.h>
#include "MAF.hpp"

int MAF::get() {
  int voltage = (analogRead(MAF_PIN)/1023)*5;

  return mapValue(voltage);
}

int MAF::mapValue(int voltage) {
  double voltageValues[] = {2.0, 2.1};
  int    MAFValues[]     = {200, 200};

  
}
