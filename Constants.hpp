#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants {
  namespace MAF {
    // MAF constants
    const float voltageValues[] = {1.8475, 2.1693, 2.3669, 2.6619, 3.0091, 3.4416, 3.8445, 3.9838, 4.2242, 4.4849, 4.7735};
    const int   airFlowValues[] = {5,      10,     15,     30,     60,     120,    190,    220,    280,    370,    480};
    const unsigned int size = sizeof(voltageValues)/sizeof(float);
  }
  namespace Engine {
    const unsigned short numberOfCylinders = 4;
    const float injectorGramsPerMinute = 153.8f;
    const int totalVolume = 2316; // cm3
  }
};

#endif
