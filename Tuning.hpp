#ifndef TUNING_H
#define TUNING_H

namespace Tuning {
  const unsigned int RPMLookup[] = {700, 1200, 1600, 2100, 2500, 2900, 3400, 3800, 4200, 4600, 5100, 5500}; // RPM
  const unsigned int loadLookup[] = {25, 32, 38, 46, 52, 60, 66, 74, 80, 88, 94, 101}; // % ABS Load
  const unsigned int XLength = 12;
  const unsigned int YLength = 12;
  
  const float AFRTable[YLength][XLength] = { // 12x12 Air Fuel Ratio table
    {12.8, 12.8, 14.1, 14.1, 14.1, 14.1, 14.0, 13.7, 13.5, 13.5, 13.5, 13.5},  // 101%
    {12.8, 12.8, 14.0, 14.0, 14.0, 14.0, 13.8, 13.5, 13.4, 13.4, 13.4, 13.4},  // 94%
    {12.8, 12.8, 13.8, 13.8, 13.8, 13.8, 13.7, 13.4, 13.2, 13.2, 13.2, 13.2},  // 88%
    {12.8, 12.8, 13.7, 13.7, 13.7, 13.7, 13.5, 13.2, 13.1, 13.1, 13.1, 13.1},  // 80%
    {12.8, 12.8, 13.6, 13.6, 13.6, 13.6, 13.4, 13.1, 13.0, 13.0, 13.0, 13.0},  // 74%
    {12.8, 12.8, 13.4, 13.4, 13.4, 13.4, 13.3, 13.0, 12.8, 12.8, 12.8, 12.8},  // 66%
    {12.8, 12.8, 13.3, 13.3, 13.3, 13.3, 13.1, 12.8, 12.7, 12.7, 12.7, 12.7},  // 60%
    {12.8, 12.8, 13.1, 13.1, 13.1, 13.1, 13.0, 12.7, 12.5, 12.5, 12.5, 12.5},  // 52%
    {12.8, 12.8, 13.0, 13.0, 13.0, 13.0, 12.9, 12.6, 12.4, 12.4, 12.4, 12.4},  // 46%
    {12.8, 12.8, 12.8, 12.8, 12.8, 12.8, 12.7, 12.4, 12.2, 12.2, 12.2, 12.2},  // 38%
    {12.8, 12.8, 12.7, 12.7, 12.7, 12.7, 12.6, 12.3, 12.1, 12.1, 12.1, 12.1},  // 32%
    {12.8, 12.8, 12.6, 12.6, 12.6, 12.6, 12.4, 12.1, 12.0, 12.0, 12.0, 12.0},  // 25%
//   700,  1200, 1600, 2100, 2500, 2900, 3400, 3800, 4200, 4600, 5100, 5500 RPM
  };
}

#endif TUNING_H
