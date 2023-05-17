#ifndef STRATEGY_DP_H
#define STRATEGY_DP_H

#include "boardlib.h"

Energy strategyDynamic(Board* board);
void fillDynamicData(Board* board, Board* data);
void printDynamicPath(Board* board);

#endif