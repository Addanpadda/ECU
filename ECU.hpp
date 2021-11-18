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

  static float calculateAFR(unsigned int rpm, unsigned int load);
  static float calculateLoad(int rpm, int airFlow);

public:
  ECU();
  void loop();
};

#endif
