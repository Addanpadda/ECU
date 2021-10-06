#include "ECU.hpp"
//#include "Constants.hpp"

ECU::ECU() {
  Serial.begin(9600);
  rpm = new RPM();
  //maf = new MAF();

  delay(1000);
}

void ECU::loop() {
  rpm->calcRPM();
  static unsigned long averageRpm = rpm->average;
  //unsigned int airFlow = maf->get();
  
  //const float airFuelRatio = 13.7f;
  
  //float airGramsPerMinute = airFlow * 1000/60;

  // airFuelRatio = airGramsPerMinute / (Constants::Engine::injectorGramsPerMinute * Constants::Engine::numberOfCylinders * openFactor);

  //float openFactor = airGramsPerMinute / (Constants::Engine::injectorGramsPerMinute * Constants::Engine::numberOfCylinders * airFuelRatio);
  //Serial.print("Open: ");
  //Serial.print(openFactor);
  //Serial.print("\tMAF: ");
  //Serial.print(airFlow);
  Serial.print("KG/H\tRPM: ");
  Serial.println(averageRpm);
}
