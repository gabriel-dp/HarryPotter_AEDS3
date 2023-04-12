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

Board createBoard(int, int);
BoardsArray createBoardsArray(int);
void printBoard(Board*);
void freeBoardsArray(BoardsArray*);

#endif