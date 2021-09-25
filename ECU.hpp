#include <Arduino.h>
#include "RPM.hpp"

class ECU {
private:
  RPM* rpm;

public:
  ECU();
  void loop();
};
