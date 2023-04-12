#include "../include/strategy.h"

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

// Searches for the globalMin Energy in the board using Inorder Traversal
int strategy1(Board* board) {
    Energy globalMin = 0;
    inOrderTraversal(1, 1, 0, 0, board, &globalMin);
    return globalMin;
}