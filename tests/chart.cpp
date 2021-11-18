#include <iostream>

/*
class Graph {
private:
    float *x;
    int   *y;
    uint size;


public:
    Graph(float *x, int *y, uint size) {
        this->x = x;
        this->y = y;
        this->size = size;
    }

    float getY(float xValue) {
        if (xValue < this->x[0]) xValue = this->x[0];
        else if (xValue > this->x[size - 1]) xValue = this->x[size - 1];

        uint xIndex = 0;
        while (xIndex < this->size && this->x[xIndex + 1] < xValue) xIndex++;

        float xSpace = this->x[xIndex + 1] - this->x[xIndex];
        float yValue = this->y[xIndex]*(((this->x[xIndex + 1]  - xValue))/xSpace) + this->y[xIndex+1]*((xValue - this->x[xIndex])/xSpace);

        return yValue;
    }
};
*/

template <class Tx, class Ty>
class Graph {
private:
    Tx *x;
    Ty *y;
    unsigned int size;


public:
    Graph(Tx *x, Ty *y, unsigned int size);

    Ty getY(Tx xValue);
};

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

    Tx xSpace = this->x[xIndex + 1] - this->x[xIndex];
    Ty yValue = this->y[xIndex]*(((this->x[xIndex + 1]  - xValue))/xSpace) + this->y[xIndex+1]*((xValue - this->x[xIndex])/xSpace);

    return yValue;
}





int main(int argc, char **argv) {
    float x[] = {2.3669, 2.6619, 3.0091, 3.4416, 3.8445, 3.9838, 4.2242, 4.4849, 4.7735};
    int   y[] = {15,     30,     60,     120,    190,    220,    280,    370,    480};
    const uint size = sizeof(x)/sizeof(float);

    Graph<float, int> *graph;
    graph = new Graph<float, int>(x, y, size);
    std::cout << graph->getY(2.0f) << std::endl;
    std::cout << graph->getY(3.0f) << std::endl;
    std::cout << graph->getY(4.0f) << std::endl;


    return 0;
}