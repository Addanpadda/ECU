
#ifndef SETTINGS_H
#define SETTINGS_H
#include "Arduino.h"

namespace Settings {
  namespace Pins {
    const unsigned int MAF = A0;
    const unsigned int RPM = 2;
    const unsigned int SPARK_ADVANCE = 3;
    const unsigned int INJECTOR = 11;
  }
  void apply();
}

#endif
