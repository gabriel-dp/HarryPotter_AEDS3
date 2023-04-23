#ifndef STRATEGY_H
#define STRATEGY_H

#include "boardlib.h"

Energy strategy1(Board*);
void depthFirstSearch(Energy, Energy, int, int, Board*, Energy*);

Energy strategy2(Board*);
void fillDynamicData(Board*, Board*);
void printDynamicPath(Board*);

#endif