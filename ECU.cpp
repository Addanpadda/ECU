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
  
  spark->SetAdvance();
  AFRTable = new Table<unsigned int, unsigned int, float>(Tuning::RPMLookup, Tuning::XLength, Tuning::loadLookup, Tuning::YLength, (float*)Tuning::AFRTable);

  delay(1000);
}

void ECU::loop() {
  rpm->calcRPM();
  
  const unsigned int averageRpm = rpm->average;
  const unsigned int airFlow = maf->get();
  const float loadAbs = calculateLoad(averageRpm, airFlow);
  const float airFuelRatio = AFRTable->getZ(averageRpm, loadAbs*100); //calculateAFR(averageRpm, (int)loadAbs*100); //13.7f;
  const float openFactor = FuelInjector::calculateOpenFactor(averageRpm, airFlow, airFuelRatio)*3;

  fuelInjector->SetOpenTime(openFactor);
  
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

static float ECU::calculateAFR(unsigned int rpm, unsigned int load) {
  /*
  // Finding the table position in the lookup
  int loadIndex = 0;
  while (loadIndex < Tuning::YLength && load >= Tuning::loadLookup[loadIndex+1]) loadIndex++;
  int rpmIndex = 0;
  while (rpmIndex < Tuning::XLength && rpm >= Tuning::RPMLookup[rpmIndex+1]) rpmIndex++;
  */
  int loadIndex = 0, rpmIndex = 0;

  if (load < Tuning::loadLookup[0]) load = Tuning::loadLookup[0];
  if (load > Tuning::loadLookup[Tuning::YLength - 1]) {
        load = Tuning::loadLookup[Tuning::YLength - 1];
        loadIndex = Tuning::YLength - 1;
  } else while (loadIndex < Tuning::YLength && load >= Tuning::loadLookup[loadIndex+1]) loadIndex++;
  if (rpm < Tuning::RPMLookup[0]) rpm = Tuning::RPMLookup[0];
  if (rpm > Tuning::RPMLookup[Tuning::XLength- 1]) {
        rpm = Tuning::RPMLookup[Tuning::XLength - 1];
        rpmIndex = Tuning::XLength - 1;
  } else while (rpmIndex < Tuning::XLength && rpm >= Tuning::RPMLookup[rpmIndex+1]) rpmIndex++;


  
  // Getting the AFRTable indexes
  int xIndex = rpmIndex;
  // Y axis is reverse in the array; Remember to -1 index when going upwards in table
  // whereas +1 will switch right on x-axis
  int yIndex = Tuning::YLength - loadIndex - 1;

  // Defining variables needed in the regression
  float firstValue, secondValue, // AFR Values to regress
  firstLookup, secondLookup,     // The values on the axis that is regressed, such as RPM on x-axis
  lookupDiff,                    // The difference between two lookup values, such as RPM jump on x-axis in table
  firstCombinedX, secondCombinedX, combinedY; // Regressed/some partly regressed values

  // Combining two of the x-axis (rpm) indexes (AFR) on the lower end of the y-axis (load) in the table
  firstValue = Tuning::AFRTable[yIndex][xIndex];
  secondValue = Tuning::AFRTable[yIndex][xIndex + 1];
  firstLookup = Tuning::RPMLookup[rpmIndex];
  secondLookup = Tuning::RPMLookup[rpmIndex + 1];
  lookupDiff = secondLookup - firstLookup; // RPM difference
  firstCombinedX = firstValue * ((secondLookup - rpm) / lookupDiff) + secondValue * ((rpm - firstLookup) / lookupDiff);

  // Combining two of the x-axis (rpm) values (AFR) on the upper end of the y-axis (load) in the table
  firstValue = Tuning::AFRTable[yIndex - 1][xIndex];
  secondValue = Tuning::AFRTable[yIndex - 1][xIndex + 1];
  secondCombinedX = firstValue * ((secondLookup - rpm) / lookupDiff) + secondValue * ((rpm - firstLookup) / lookupDiff);

  // Combining two already combined y-axis (load) values (AFR): firstCombinedX and secondCombinedX
  firstValue = firstCombinedX; 
  secondValue = secondCombinedX;
  firstLookup = Tuning::loadLookup[loadIndex];
  secondLookup = Tuning::loadLookup[loadIndex + 1];
  lookupDiff = secondLookup - firstLookup; // Load difference
  combinedY = firstValue * ((secondLookup - load) / lookupDiff) + secondValue * ((load - firstLookup) / lookupDiff);
  
  return combinedY; // Completely combined
}
