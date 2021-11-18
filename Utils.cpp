#include "Utils.hpp"

template <class Tx, class Ty>
Graph<Tx, Ty>::Graph(Tx *x, Ty *y, unsigned int size) {
    this->x = x;
    this->y = y;
    this->size = size;
}

template <class Tx, class Ty>
Ty Graph<Tx, Ty>::getY(Tx xValue) {
    if (xValue < this->x[0]) xValue = this->x[0];
    else if (xValue > this->x[size - 1]) xValue = this->x[size - 1];

    unsigned int xIndex = 0;
    while (xIndex < this->size && this->x[xIndex + 1] < xValue) xIndex++;

    float xSpace = this->x[xIndex + 1] - this->x[xIndex];
    float yValue = this->y[xIndex]*(((this->x[xIndex + 1]  - xValue))/xSpace) + this->y[xIndex+1]*((xValue - this->x[xIndex])/xSpace);

    return yValue;
}
