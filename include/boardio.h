#ifndef BOARDIO_H
#define BOARDIO_H

#include "boardlib.h"

void throwFileError(char*);
BoardsArray getBoardsFromInput(char*);
void saveResultsOnOutput(char*, Energy*, int);

#endif