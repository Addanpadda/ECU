#include <iostream>

struct Vec2D {
	int x, y;
};


class Table {
private:
	unsigned int *lookupRPM;  
	unsigned int *lookupLoad;
	unsigned int XLength;                                                                        	  
	unsigned int YLength;
		  
	float **AFRTable;


	float firstValue, secondValue, // AFR Values to regress
	firstLookup, secondLookup,     // The values on the axis that is regressed, such as RPM on x-axis
	lookupDiff,                    // The difference between two lookup values, such as RPM jump on x-axis in table
	firstCombinedX, secondCombinedX, combined; // Regressed/some partly regressed values
																							





	class TablePosition {
	private:
		Vec2D table;
		Vec2D lookup;
		decltype(XLength) _XLength;
		decltype(YLength) _YLength;

	public:
		void printLength() {
			std::cout << _XLength << std::endl;
		}

		void setLookup(Vec2D _lookup) {
			this->lookup = _lookup;
			this->table.x = _lookup.x;
			this->table.y = _YLength - _lookup.y - 1;
		}

		Vec2D getTable() {
			return this->table;
		}

		Vec2D getLookup() {
			return this->lookup;
		}

		TablePosition getNextX() {
			Vec2D temp;

			temp.y = this->lookup.y;
			temp.x = this->lookup.x + 1;
			if (temp.x >= _XLength) temp.x = _XLength - 1;

			TablePosition tablePosition;
			tablePosition.setLookup(temp);

			return tablePosition;
		}

		TablePosition getNextY() {
			Vec2D temp;

			temp.x = this->lookup.x;
			temp.y = this->lookup.y - 1;
			if (temp.y < 0) temp.y = 0;

			TablePosition tablePosition;
			tablePosition.setLookup(temp);

			return tablePosition;
		}
	};






public:
	Table(float _table[][12], unsigned int _lookupX[], unsigned int _lookupY[]) {
		this->AFRTable = _table;
		this->lookupRPM = _lookupX;
		this->lookupLoad = _lookupY;

		XLength = sizeof(lookupRPM)/sizeof(int);                                                                        	  
		YLength = sizeof(lookupLoad)/sizeof(int);

		TablePosition tablePosition;
		tablePosition.printLength();
	};

/*
	float getData(unsigned int load, unsigned int rpm) {

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

	}

	float combineX(int firstXIndex, int secondXIndex, int yIndex) {
		firstValue = AFRTable[yIndex][firstXIndex];
		secondValue = AFRTable[yIndex][secondXIndex];
		firstLookup = lookupRPM[rpmIndex];
		secondLookup = lookupRPM[rpmIndex + 1];
		lookupDiff = secondLookup - firstLookup; // RPM difference
		firstCombinedX = firstValue * ((secondLookup - rpm) / lookupDiff) + secondValue * ((rpm - firstLookup) / lookupDiff);


	}

	float combineY() {
	
	}
	
	float combine() {
	
	}

*/
};





int main() {


	unsigned int lookupRPM[] = {700, 1200, 1600, 2100, 2500, 2900, 3400, 3800, 4200, 4600, 5100, 5500}; // RPM
	unsigned int lookupLoad[] = {25, 32, 38, 46, 52, 60, 66, 74, 80, 88, 94, 101}; // % ABS Load    

	float table[12][12] =
	{ // 12x12 Air Fuel Ratio table
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

	Table dstable(table, lookupRPM, lookupLoad);

	return 0;
}