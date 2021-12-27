#include "ECU.hpp"
#include "Constants.hpp"
#include "Settings.hpp"
#include "Tuning.hpp"

#include "Utils.hpp"

ECU::ECU() {
  Serial.begin(2000000);
  Settings::apply();
  
  rpm = new RPM();
  maf = new MAF(Settings::Pins::MAF);
  fuelInjector = new FuelInjector(Settings::Pins::INJECTOR);
  spark = new Spark(Settings::Pins::SPARK_ADVANCE);
  //idleAirControlValve = new Transistor(Settings::Pins::AIR_IDLE_CONTROL_VALVE);
  
  spark->SetAdvance();
  //idleAirControlValve->setOpenFactor(0.0);
  AFRTable = new Table<unsigned int, unsigned int, float>(Tuning::RPMLookup, Tuning::XLength, Tuning::loadLookup, Tuning::YLength, (float*)Tuning::AFRTable);

  delay(1000);
}

void ECU::loop() {
  rpm->calcRPM();
  
  const unsigned int averageRpm = rpm->average;
  const unsigned int airFlow = maf->get();
  
  const float loadAbs = calculateLoad(averageRpm, airFlow);
  const float airFuelRatio = AFRTable->getZ(averageRpm, loadAbs*100);
  const float openFactor = FuelInjector::calculateOpenFactor(averageRpm, airFlow, airFuelRatio);

  fuelInjector->setOpenFactor(openFactor);
  
  Serial.print("Open: ");
  Serial.print(openFactor*255);
  Serial.print("\tMAF: ");
  Serial.print((analogRead(A0)/1023.0)*5.0);
  Serial.print("V; ");
  Serial.print(airFlow);
  Serial.print("KG/H\tRPM: ");
  Serial.print(averageRpm);
  Serial.print("\tLOAD: ");
  Serial.print(loadAbs);
  Serial.print("\tAFR: ");
  Serial.println(airFuelRatio);  
}

static float ECU::calculateLoad(int rpm, int airFlow) {
  if (rpm == 0) return 0.0f;
  
  // LOAD_ABS = [air mass (g / intake stroke)] / [1.184 (g / intake stroke) * cylinder displacement in liters]
  float airMass = airFlow * 1000.0 / 60.0 / rpm / (Constants::Engine::numberOfCylinders/2.0); // Divided by two because every two revs, all cylinders take in air.
  float loadAbs = airMass / (1.184 * Constants::Engine::totalVolume / 1000);

  return abs(loadAbs);
}