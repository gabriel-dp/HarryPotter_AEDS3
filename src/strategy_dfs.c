#include "../include/strategy_dfs.h"

#include <stdio.h>

#include "../include/boardlib.h"

// Solves the board using Depth-First Search
Energy strategyDFS(Board* board, int enablePruning) {
    Energy globalMin = enablePruning ? greedyPath(board) : 0;
    depthFirstSearch(1, 1, 0, 0, board, &globalMin, enablePruning);
    return globalMin;
}

// Browses all paths of the matrix going only right and down, searching for the lowest globalMin
void depthFirstSearch(Energy actual, Energy min, int r, int c, Board* board, Energy* globalMin, int enablePruning) {
    // Sum squareEnergy to actual Energy
    Energy squareEnergy = board->matrix[r][c].energy;
    actual += squareEnergy;

    // Increase minimum Energy to prevent actual Energy from being 0 or less
    if (actual <= 0) {
        min -= (actual - 1);
        actual = 1;
    }

    // Activate Branch and Bound if enablePruning is true
    if (enablePruning && min >= *globalMin) return;

    // Check if reach the last Square
    if (r == board->rows - 1 && c == board->columns - 1) {
        // Compares globalMin Energy to actual path min Energy
        if (*globalMin > min || *globalMin == 0) {
            *globalMin = min;
        }
    } else {
        if (r + 1 < board->rows) {
            // Continue path in the bottom square if it exists
            depthFirstSearch(actual, min, r + 1, c, board, globalMin, enablePruning);
        }
        if (c + 1 < board->columns) {
            // Continue path in the right square if it exists
            depthFirstSearch(actual, min, r, c + 1, board, globalMin, enablePruning);
        }
    }
}

// Get a approximate result with a greedy algorythm
Energy greedyPath(Board* board) {
    // Initialize variables
    Energy min = 1, actual = 1;
    int r = 0, c = 0;

    while (1) {
        // Sum squareEnergy to actual Energy
        actual += board->matrix[r][c].energy;

        // Increase minimum Energy to prevent actual Energy from being 0 or less
        if (actual <= 0) {
            min -= (actual - 1);
            actual = 1;
        }

        // Check if both directions are avaliable
        if (r < board->rows - 1 && c < board->columns - 1) {
            // Select the smallest option in the moment and updates the position
            if (board->matrix[r + 1][c].energy > board->matrix[r][c + 1].energy) {
                r++;
            } else {
                c++;
            }
        } else {
            if (r < board->rows - 1) {
                r++;
            } else if (c < board->columns - 1) {
                c++;
            } else {
                // Reached last square
                break;
            }
        }
    }

    // Returns the greedy solution
    return min;
}
