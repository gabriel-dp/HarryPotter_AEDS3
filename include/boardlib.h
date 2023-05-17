#ifndef BOARDLIB_H
#define BOARDLIB_H

typedef int Energy;

typedef struct {
    Energy energy;
} Square;

typedef struct {
    int rows, columns;
    Square** matrix;
} Board;

typedef struct {
    int length;
    Board* boards;
} BoardsArray;

Board createBoard(int rows, int columns);
BoardsArray createBoardsArray(int length);
void printBoard(Board* board);
void freeBoard(Board* board);
void freeBoardsArray(BoardsArray* array);

#endif