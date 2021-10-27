#include "ECU.hpp"
#include "Constants.hpp"
#include "Settings.hpp"

ECU::ECU() {
  //Serial.begin(2000000);
  Settings::apply();
  
  rpm = new RPM();
  maf = new MAF(Settings::Pins::MAF);
  fuelInjector = new FuelInjector(Settings::Pins::INJECTOR);
  spark = new Spark(Settings::Pins::SPARK_ADVANCE);
  
  spark->SetAdvance();

  delay(1000);
}

void ECU::loop() {
  rpm->calcRPM();
  unsigned long averageRpm = rpm->average;

  unsigned int airFlow = maf->get();
  
  const float airFuelRatio = 13.7f;
  
  float airGramsPerMinute = airFlow * 1000.0/60.0;

  //airFuelRatio = airGramsPerMinute / (Constants::Engine::injectorGramsPerMinute * Constants::Engine::numberOfCylinders * openFactor);

  float openFactor;
  if (averageRpm == 0) openFactor = 0;
  else if (averageRpm > 20000) openFactor = .012*airFlow;
  else openFactor = (airGramsPerMinute / (Constants::Engine::injectorGramsPerMinute * Constants::Engine::numberOfCylinders * airFuelRatio))*3;
  /*
  Serial.print("Open: ");
  Serial.print(openFactor*255);
  Serial.print("\tMAF: ");
  Serial.print((analogRead(A0)/1023.0)*5.0);
  Serial.print("V; ");
  Serial.print(airFlow);
  Serial.print("KG/H\tRPM: ");
  Serial.println(averageRpm);
  */

  
  fuelInjector->SetOpenTime(openFactor);
}
