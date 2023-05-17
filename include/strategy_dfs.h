#ifndef STRATEGY_DFS_H
#define STRATEGY_DFS_H

#include "boardlib.h"

Energy strategyDFS(Board*, int);
void depthFirstSearch(Energy, Energy, int, int, Board*, Energy*, int);
Energy greedyPath(Board* board);

#endif