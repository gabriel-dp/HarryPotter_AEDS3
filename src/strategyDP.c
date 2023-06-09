#include "../include/strategyDP.h"

#include <stdio.h>
#include <stdlib.h>

#include "../include/boardlib.h"

// Solves the board using Dynamic Programming
Energy strategyDynamic(Board* board) {
    // Creates a new temp Board to store minimum energy of each square
    Board data = createBoard(board->rows, board->columns);

    // Fills minimum Energy matrix and get the result from the first Square
    fillDynamicData(board, &data);
    Energy result = data.matrix[0][0].energy;

    // Displays path in console (disabled by default)
    // printDynamicPath(&data);

    // Deallocates Board data
    freeBoard(&data);

    return result;
}

// Fills each Square data in the matrix from the end to the beginning
void fillDynamicData(Board* board, Board* data) {
    // Browses all squares starting on the last square
    for (int r = board->rows - 1; r >= 0; r--) {
        for (int c = board->columns - 1; c >= 0; c--) {
            // Gets actual, bottom and right Squares in the matrix
            Square* dataActual = &(data->matrix[r][c]);
            Square* dataBottom = (r < board->rows - 1) ? &(data->matrix[r + 1][c]) : NULL;
            Square* dataRight = (c < board->columns - 1) ? &(data->matrix[r][c + 1]) : NULL;

            // Gets the lowest Energy between the previous Squares (bottom and right)
            Energy previousEnergy = 1;
            if (dataBottom && dataRight) {
                previousEnergy = dataBottom->energy < dataRight->energy ? dataBottom->energy : dataRight->energy;
            } else {
                if (dataBottom) {
                    previousEnergy = dataBottom->energy;
                } else if (dataRight) {
                    previousEnergy = dataRight->energy;
                }
            }

            // Adds the actual energy to the previous minimum Energy
            dataActual->energy = previousEnergy - board->matrix[r][c].energy;

            // Adjusts minimum Energy to never be less than 1
            if (dataActual->energy < 1) {
                dataActual->energy = 1;
            }
        }
    }
}

// Prints the path created in Dynamic Programming strategy
// Paste the points in https://www.desmos.com/calculator input
void printDynamicPath(Board* data) {
    // Row and column coordinates
    int r = 0, c = 0;

    // Pointer to the lowest coordinate
    int* lowest;

    // Prints entire path until reach the last Square
    do {
        // Prints 'r' and 'c' transformed in 'x' and 'y'
        float x = c + 0.5;
        float y = data->rows - r - 0.5;
        printf("(%.1f, %.1f)", x, y);

        // Selects the lowest coordinate between 'r' and 'c'
        if (r < data->rows - 1 && c < data->columns - 1) {
            lowest = (data->matrix[r + 1][c].energy < data->matrix[r][c + 1].energy) ? &r : &c;
        } else {
            if (r < data->rows - 1) {
                lowest = &r;
            } else if (c < data->columns - 1) {
                lowest = &c;
            } else {
                lowest = NULL;
            }
        }

        // Update the selected lowest coordinate
        if (lowest != NULL) {
            (*lowest)++;
            printf(", ");
        }

    } while (lowest != NULL);
    printf("\n");
}