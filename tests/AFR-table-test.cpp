#include <iostream>

int main() {
	/*
  const unsigned int VETableX[] = {400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2400, 2800, 3200, 3700, 4200, 4800, 5500};
  const unsigned int VETableY[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
 	
  const unsigned int XLength = sizeof(VETableX)/sizeof(int);
  const unsigned int YLength = sizeof(VETableY)/sizeof(int);
  
  const short float VETable[YLength][XLength] = {
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 100%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 95%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 90%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 85%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 80%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 75%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 70%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 65%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 60%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 55%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 50%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 45%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 40%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 35%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 30%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 25%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 20%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 15%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 10%
    {100, 100, 100, 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100},  // 5%
//   400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2400, 2800, 3200, 3700, 4200, 4800, 5500   RPM
  };


	int load = 20;
	int rpm = 1500;

	int loadIndex = 0;
	while (loadIndex < YLength && load >= VETableY[loadIndex+1]) loadIndex++;

	int rpmIndex = 0;
	while (rpmIndex < XLength && rpm >= VETableX[rpmIndex+1]) rpmIndex++;


	std::cout << VETable[YLength - loadIndex][rpmIndex] << std::endl;
	std::cout << "Y: " << loadIndex << "\tX: " << rpmIndex << std::endl;
*/

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
	                                                                                                                               
	 int loadIndex = 0;
	 while (loadIndex < YLength && load >= VETableY[loadIndex+1]) loadIndex++;

	 int rpmIndex = 0;
	 while (rpmIndex < XLength && rpm >= VETableX[rpmIndex+1]) rpmIndex++;
	                                                                                                                               
	                                                                                                                               
	 std::cout << VETable[YLength - loadIndex - 1][rpmIndex] << std::endl;
	 std::cout << "Y: " << YLength - loadIndex - 1 << "\tX: " << rpmIndex << std::endl;




	int xIndex = rpmIndex;
	int yIndex = YLength - loadIndex - 1;


	float firstXValue = VETable[yIndex][xIndex];
	float secondXValue = VETable[yIndex][xIndex + 1];
	float firstLookupX = VETableX[rpmIndex];
	float secondLookupX = VETableX[rpmIndex + 1];
	float lookupDiff = secondLookupX - firstLookupX;
	float firstCombinedX = firstXValue * ((secondLookupX - rpm) / lookupDiff) + secondXValue * ((rpm - firstLookupX) / lookupDiff);
//	std::cout << firstLookupX - rpm << "\t" << secondLookupX -rpm << std::endl;
	std::cout << firstCombinedX << std::endl;

	firstXValue = VETable[yIndex - 1][xIndex];
	secondXValue = VETable[yIndex - 1][xIndex + 1];
	float secondCombinedX = firstXValue * ((secondLookupX - rpm) / lookupDiff) + secondXValue * ((rpm - firstLookupX) / lookupDiff);
//	std::cout << firstLookupX - rpm << "\t" << secondLookupX -rpm << std::endl;
	std::cout << secondCombinedX << std::endl;





	float firstYValue = firstCombinedX;
	float secondYValue = secondCombinedX;
	float firstLookupY = VETableY[loadIndex];
	float secondLookupY = VETableY[loadIndex + 1];
	lookupDiff = secondLookupY - firstLookupY;
	std::cout << "firstYValue: " << firstYValue << "\t" << "secondYValue: " << secondYValue << "\t" << "firstLookupY: " << firstLookupY << "\t" << "secondLookupY: " << secondLookupY << std::endl;
	float combinedY = firstYValue * ((secondLookupY - load) / lookupDiff) + secondYValue * ((load - firstLookupY) / lookupDiff);	 
	std::cout << combinedY << std::endl;

	return 0;
 }
