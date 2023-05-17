#ifndef STRATEGY_DFS_H
#define STRATEGY_DFS_H

#include "boardlib.h"

Energy strategyDFS(Board* board, int enablePruning);
void depthFirstSearch(Energy actual, Energy min, int r, int c, Board* board, Energy* globalMin, int enablePruning);
Energy greedyPath(Board* board);

#endif