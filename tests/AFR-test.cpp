#include <iostream>

int main() {
	const unsigned int VETableX[] = {700, 1200, 1600, 2100, 2500, 2900, 3400, 3800, 4200, 4600, 5100, 5500}; // RPM
	const unsigned int VETableY[] = {25, 32, 38, 46, 52, 60, 66, 74, 80, 88, 94, 101}; // % Load
	 
	const unsigned int XLength = sizeof(VETableX)/sizeof(int);
	const unsigned int YLength = sizeof(VETableY)/sizeof(int);
	
	const float VETable[YLength][XLength] = {
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
//	   700,  1200, 1600, 2100, 2500, 2900, 3400, 3800, 4200, 4600, 5100, 5500 RPM
	};
	                                                                                                                               
	                                                                                                                               
	 int load = 35;
	 int rpm = 3500;

	int loadIndex = 0, rpmIndex = 0;
		Vec2D lookup;
																																		
		if (load < lookupLoad[0]) load = lookupLoad[0];
		if (load > lookupLoad[YLength - 1]) {
				load = lookupLoad[YLength - 1];
				lookup.y = 0;
		} else while (loadIndex < YLength && load >= lookupLoad[loadIndex+1]) loadIndex++;
		//if (rpm < lookupRPM[0]) rpm = lookupRPM[0];
		if (rpm > lookupRPM[XLength- 1]) {
				rpm = lookupRPM[XLength - 1];
				lookup.x = XLength - 1;
		} else while (lookup.x < XLength && rpm >= lookupRPM[lookup.x+1]) lookup.x++;
																															
		std::cout << loadIndex << "; " << rpmIndex << std::endl;	 
		std::cout << AFRTable[YLength - loadIndex - 1][rpmIndex] << std::endl;
		std::cout << "Y: " << YLength - loadIndex - 1 << "\tX: " << rpmIndex << std::endl;
																																	
																																		
																																		
		int xIndex = lookup.x;
		// Y axis is reverse in the array; Remember to -1 index when going upwards in table
		// whereas +1 will switch right on x-axis
		int yIndex = YLength - lookup.y - 1;



																																																																		
		
																																			
		firstValue = AFRTable[yIndex][xIndex];
		secondValue = AFRTable[yIndex][xIndex + 1];
		firstLookup = lookupRPM[rpmIndex];
		secondLookup = lookupRPM[rpmIndex + 1];
		lookupDiff = secondLookup - firstLookup; // RPM difference
		firstCombinedX = firstValue * ((secondLookup - rpm) / lookupDiff) + secondValue * ((rpm - firstLookup) / lookupDiff);
																																		
		firstValue = AFRTable[yIndex - 1][xIndex];
		secondValue = AFRTable[yIndex - 1][xIndex + 1];
		secondCombinedX = firstValue * ((secondLookup - rpm) / lookupDiff) + secondValue * ((rpm - firstLookup) / lookupDiff);
																																		
		firstValue = firstCombinedX; 
		secondValue = secondCombinedX;                                                                                                
		firstLookup = lookupLoad[loadIndex];
		secondLookup = lookupLoad[loadIndex + 1];
		lookupDiff = secondLookup - firstLookup; // Load difference
		combined = firstValue * ((secondLookup - load) / lookupDiff) + secondValue * ((load - firstLookup) / lookupDiff);	 
		std::cout << combined << std::endl;	 
		std::cout << combined << std::endl;

	return 0;
 }
