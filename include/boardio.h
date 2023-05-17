#ifndef BOARDIO_H
#define BOARDIO_H

#include "boardlib.h"

void throwFileError(char* message);
BoardsArray getBoardsFromInput(char* inputPath);
void saveResultsOnOutput(char* outputPath, Energy* results, int resultsLength);

#endif