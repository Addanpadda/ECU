#include <iostream>

template <class Tx, class Ty, class Tz>
class Table {
private:
    Tx *lookupX;
    Ty *lookupY;
    int XLength;
    int YLength;
    Tz *table;


	Tz getTableValue(int i1, int i2) {
		return (&table)[0][i2 + i1 * YLength];
	}

public:
    Table(Tx *lookupX, int XLength, Ty *lookupY, int YLength, Tz *table) {
        this->lookupX = lookupX;
        this->XLength = XLength;
        this->lookupY = lookupY;
        this->YLength = YLength;
        this->table = table;

        //std::cout << (&table)[0][20] << std::endl;
        //std::cout << lookupY[0] << std::endl;
    }

    Tz getZ(Tx rpm, Ty load) {

        int loadIndex = 0, rpmIndex = 0;

        if (load < lookupY[0]) load = lookupY[0];
        if (load > lookupY[YLength - 1]) {
                load = lookupY[YLength - 1];
                loadIndex = YLength - 1;
        } else while (loadIndex < YLength && load >= lookupY[loadIndex+1]) loadIndex++;
        if (rpm < lookupX[0]) rpm = lookupX[0];
        if (rpm > lookupX[XLength- 1]) {
                rpm = lookupX[XLength - 1];
                rpmIndex = XLength - 1;
        } else while (rpmIndex < XLength && rpm >= lookupX[rpmIndex+1]) rpmIndex++;                                                                                                                          



        std::cout << loadIndex << "; " << rpmIndex << std::endl;
        std::cout << getTableValue(YLength - loadIndex - 1, rpmIndex) << std::endl;
        std::cout << "Y: " << YLength - loadIndex - 1 << "\tX: " << rpmIndex << std::endl;
       

        int xIndex = rpmIndex;
        // Y axis is reverse in the array; Remember to -1 index when going upwards in table
        // whereas +1 will switch right on x-axis
        int yIndex = YLength - loadIndex - 1;



        Tz firstValue, secondValue, // AFR Values to regress
        firstLookup, secondLookup,     // The values on the axis that is regressed, such as RPM on x-axis
        lookupDiff,                    // The difference between two lookup values, such as RPM jump on x-axis in (&table)
        firstCombinedX, secondCombinedX, combined; // Regressed/some partly regressed values


        firstValue = getTableValue(yIndex, xIndex);
        secondValue = getTableValue(yIndex, xIndex + 1);
        firstLookup = lookupX[rpmIndex];
        secondLookup = lookupX[rpmIndex + 1];
        lookupDiff = secondLookup - firstLookup; // RPM difference
        firstCombinedX = firstValue * ((secondLookup - rpm) / lookupDiff) + secondValue * ((rpm - firstLookup) / lookupDiff);

        firstValue = getTableValue(yIndex - 1, xIndex);
        secondValue = getTableValue(yIndex - 1, xIndex + 1);
        secondCombinedX = firstValue * ((secondLookup - rpm) / lookupDiff) + secondValue * ((rpm - firstLookup) / lookupDiff);

        firstValue = firstCombinedX; 
        secondValue = secondCombinedX;
        firstLookup = lookupY[loadIndex];
        secondLookup = lookupY[loadIndex + 1];
        lookupDiff = secondLookup - firstLookup; // Load difference
        combined = firstValue * ((secondLookup - load) / lookupDiff) + secondValue * ((load - firstLookup) / lookupDiff);	 
	
        return combined;
    }
};

int main() {
	unsigned int lookupX[] = {700, 1200, 1600, 2100, 2500, 2900, 3400, 3800, 4200, 4600, 5100, 5500}; // RPM
	unsigned int lookupY[] = {25, 32, 38, 46, 52, 60, 66, 74, 80, 88, 94, 101}; // % ABS Load
	const unsigned int XLength = 12;
	const unsigned int YLength = 12;
	
	float table[YLength][XLength] = { // 12x12 Air Fuel Ratio table
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
	                                                                                                                               
	                                                                                                                               
    unsigned int load = 70;
    unsigned int rpm = 3600;

    Table< unsigned int, unsigned int, float > *tble;
    //tble = new Table<unsigned int, unsigned int, float>(lookupX, 12, YLength, 12, table);
    tble = new Table< unsigned int, unsigned int, float >(lookupX, 12, lookupY, 12, (float*)table);

    std::cout << tble->getZ(rpm, load) << std::endl;

	return 0;
 }
