#include "../include/boardlib.h"

#include <stdio.h>
#include <stdlib.h>

// Creates a new empty Board with the given rows and columns
Board createBoard(int rows, int columns) {
    Board newBoard;
    newBoard.rows = rows;
    newBoard.columns = columns;

    // Dynamically allocates the matrix of Squares
    newBoard.matrix = (Square**)malloc(rows * sizeof(Square*));
    for (int i = 0; i < rows; i++) {
        newBoard.matrix[i] = (Square*)malloc(columns * sizeof(Square));
    }

    return newBoard;
}

// Creates a new empty array of Boards (not allocate each Board)
BoardsArray createBoardsArray(int length) {
    BoardsArray newArray;
    newArray.length = length;
    newArray.boards = (Board*)malloc(sizeof(Board) * length);

    return newArray;
}

// Prints all Board Squares
void printBoard(Board* board) {
    for (int r = 0; r < board->rows; r++) {
        for (int c = 0; c < board->columns; c++) {
            printf("%d ", board->matrix[r][c].energy);
        }
        printf("\n");
    }
}

// Deallocates entire BoardsArray structure
void freeBoardsArray(BoardsArray* array) {
    for (int b = 0; b < array->length; b++) {
        for (int r = 0; r < array->boards[b].rows; r++) {
            // Deallocates Board columns
            free(array->boards[b].matrix[r]);
        }
        // Deallocates Board rows
        free(array->boards[b].matrix);
    }
    // Deallocates BoardsArray
    free(array->boards);
}