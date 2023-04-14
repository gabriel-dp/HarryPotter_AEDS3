#include "../include/strategy.h"

#include <stdio.h>
#include <stdlib.h>

// Searches for the globalMin Energy in the board using Inorder Traversal
int strategy1(Board* board) {
    Energy globalMin = 0;
    inOrderTraversal(1, 1, 0, 0, board, &globalMin);
    return globalMin;
}

// Browses all paths of the matrix going only right and down, searching for the lowest globalMin
void inOrderTraversal(Energy actual, Energy min, int r, int c, Board* board, Energy* globalMin) {
    // Sum squareEnergy to actual Energy
    Energy squareEnergy = board->matrix[r][c].energy;
    actual += squareEnergy;

    // Increase minimum Energy to prevent actual Energy from being 0 or less
    if (actual <= 0) {
        min -= (actual - 1);
        actual = 1;
    }

    // Checks if reach the last Square
    if (r == board->rows - 1 && c == board->columns - 1) {
        // Compares globalMin Energy to actual path min Energy
        if (*globalMin > min || *globalMin == 0) {
            *globalMin = min;
        }
    } else {
        if (r + 1 < board->rows) {
            // Continue path in the bottom square if it exists
            inOrderTraversal(actual, min, r + 1, c, board, globalMin);
        }
        if (c + 1 < board->columns) {
            // Continue path in the right square if it exists
            inOrderTraversal(actual, min, r, c + 1, board, globalMin);
        }
    }
}

// Searches for the globalMin Energy in the board using Dynamic Programming
int strategy2(Board* board) {
    // Dynamically allocates the matrix of DataSquares
    DataSquare** data = (DataSquare**)malloc(board->rows * sizeof(DataSquare*));
    for (int r = 0; r < board->rows; r++) {
        data[r] = (DataSquare*)malloc(board->columns * sizeof(DataSquare));
    }

    // Fills DataSquare matrix and get the result from the last position
    fillDataDynamically(board, data);
    int result = data[board->rows - 1][board->columns - 1].min;

    // printPath(board, data);

    // Deallocates DataSquare matrix
    for (int r = 0; r < board->rows; r++) {
        free(data[r]);
    }
    free(data);

    return result;
}

// Fills each DataSquare in the matrix until the last position
void fillDataDynamically(Board* board, DataSquare** data) {
    // Browses the matrix by diagonals
    for (int k = 0; k < (board->rows + board->columns - 1); k++) {
        for (int r = 0; r <= k; r++) {
            int c = k - r;

            // Avoid invalid positions
            if (r >= board->rows || c >= board->columns) continue;

            // Get actual and previous squares
            DataSquare* dataSquare = &(data[r][c]);
            Square* square = &(board->matrix[r][c]);
            Square* squareTop = r > 0 ? &(board->matrix[r - 1][c]) : NULL;
            Square* squareLeft = c > 0 ? &(board->matrix[r][c - 1]) : NULL;

            // Checks if is the BOARD_START
            if (!squareTop && !squareLeft) {
                dataSquare->origin = SQUARE_START;
                dataSquare->actual = 1 + square->energy;
                dataSquare->min = 1;
            } else {
                // Defines bestOrigin as SQUARE_TOP or SQUARE_LEFT
                int bestOrigin = squareTop && (data[r - 1][c].min < data[r][c - 1].min) ? SQUARE_TOP : SQUARE_LEFT;
                dataSquare->origin = bestOrigin;

                // Sums actual Energy to the best previous Energy
                if (bestOrigin == SQUARE_TOP) {
                    dataSquare->actual = data[r - 1][c].actual + square->energy;
                    dataSquare->min = data[r - 1][c].min;
                } else {
                    dataSquare->actual = data[r][c - 1].actual + square->energy;
                    dataSquare->min = data[r][c - 1].min;
                }
            }

            // Adjusts min Energy if actual life is or less
            if (dataSquare->actual <= 0) {
                dataSquare->min -= (dataSquare->actual - 1);
                dataSquare->actual = 1;
            }
        }
    }
}

void printPath(Board* board, DataSquare** data) {
    int r = board->rows - 1, c = board->columns - 1;
    while (data[r][c].origin != SQUARE_START) {
        printf("(r=%d, c=%d)\n", r + 1, c + 1);
        if (data[r][c].origin == SQUARE_TOP)
            r--;
        else
            c--;
    }
    printf("(r=1, c=1)\n");
}