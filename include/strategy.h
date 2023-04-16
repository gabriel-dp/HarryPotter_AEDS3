#ifndef STRATEGY_H
#define STRATEGY_H

#include "boardlib.h"

// Strategy 2 constants
#define SQUARE_START 0
#define SQUARE_LEFT 1
#define SQUARE_TOP 2

// Strategy 2 data structure
typedef struct {
    Energy actual, min;
    int origin;
} DataSquare;

Energy strategy1(Board*);
void depthFirstSearch(Energy, Energy, int, int, Board*, Energy*);

Energy strategy2(Board*);
void fillDataDynamically(Board*, DataSquare**);
void printPath(Board*, DataSquare**);

#endif