#ifndef ECU_H
#define ECU_H

#include <Arduino.h>
#include "RPM.hpp"
#include "MAF.hpp"
#include "FuelInjector.hpp"
#include "Spark.hpp"

class ECU {
private:
  RPM* rpm;
  MAF* maf;
  FuelInjector* fuelInjector;
  Spark * spark;

public:
  ECU();
  void loop();
};

#endif
