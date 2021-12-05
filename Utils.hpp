#ifndef UTILS_H
#define UTILS_H


template <class Tx, class Ty>
class Graph {
private:
    Tx *x;
    Ty *y;
    unsigned int size;


public:
    Graph(Tx *x, Ty *y, unsigned int size) {
	    this->x = x;
	    this->y = y;
	    this->size = size;
	}


    Ty getY(Tx xValue) {
	    if (xValue < this->x[0]) xValue = this->x[0];
	    else if (xValue > this->x[size - 1]) xValue = this->x[size - 1];
	
	    unsigned int xIndex = 0;
	    while (xIndex < this->size && this->x[xIndex + 1] < xValue) xIndex++;
	
	    float xSpace = this->x[xIndex + 1] - this->x[xIndex];
	    float yValue = this->y[xIndex]*(((this->x[xIndex + 1]  - xValue))/xSpace) + this->y[xIndex+1]*((xValue - this->x[xIndex])/xSpace);
	
	    return yValue;
	}
};

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

    Tz getZ(Tx x, Ty y) {

        int yIndex = 0, xIndex = 0;

        if (y < lookupY[0]) y = lookupY[0];
        if (y > lookupY[YLength - 1]) {
                y = lookupY[YLength - 1];
                yIndex = YLength - 1;
        } else while (yIndex < YLength && y >= lookupY[yIndex+1]) yIndex++;
        if (x < lookupX[0]) x = lookupX[0];
        if (x > lookupX[XLength- 1]) {
                x = lookupX[XLength - 1];
                xIndex = XLength - 1;
        } else while (xIndex < XLength && x >= lookupX[xIndex+1]) xIndex++;                                                                                                                          
       

        // Y axis is reverse in the array; Remember to -1 index when going upwards in table
        // whereas +1 will switch right on x-axis
        yIndex = YLength - yIndex - 1;



        Tz firstValue, secondValue, // AFR Values to regress
        firstLookup, secondLookup,     // The values on the axis that is regressed, such as RPM on x-axis
        lookupDiff,                    // The difference between two lookup values, such as RPM jump on x-axis in (&table)
        firstCombinedX, secondCombinedX, combined; // Regressed/some partly regressed values


        firstValue = getTableValue(yIndex, xIndex);
        secondValue = getTableValue(yIndex, xIndex + 1);
        firstLookup = lookupX[xIndex];
        secondLookup = lookupX[xIndex + 1];
        lookupDiff = secondLookup - firstLookup; // RPM difference
        firstCombinedX = firstValue * ((secondLookup - x) / lookupDiff) + secondValue * ((x - firstLookup) / lookupDiff);

        firstValue = getTableValue(yIndex - 1, xIndex);
        secondValue = getTableValue(yIndex - 1, xIndex + 1);
        secondCombinedX = firstValue * ((secondLookup - x) / lookupDiff) + secondValue * ((x - firstLookup) / lookupDiff);

        firstValue = firstCombinedX; 
        secondValue = secondCombinedX;
        firstLookup = lookupY[yIndex];
        secondLookup = lookupY[yIndex + 1];
        lookupDiff = secondLookup - firstLookup; // Load difference
        combined = firstValue * ((secondLookup - y) / lookupDiff) + secondValue * ((y - firstLookup) / lookupDiff);   
  
        return combined;
    }
};

#endif
