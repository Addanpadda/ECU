#ifndef UTILS_H
#define UTILS_H


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

#endif
