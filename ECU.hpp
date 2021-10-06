#ifndef ECU_H
#define ECU_H

#include <Arduino.h>
#include "RPM.hpp"
//#include "MAF.hpp"

class ECU {
private:
  RPM* rpm;
//  MAF* maf;

public:
  ECU();
  void loop();
};

#endif
