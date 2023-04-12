#include "../include/boardio.h"

#include <stdio.h>
#include <stdlib.h>

// Stops the program if an error occurs with the files
void throwFileError(char* message) {
    printf("FILE ERROR - %s\n", message);
    exit(EXIT_FAILURE);
}

// The input file contains the total number of boards + each one dimensions and values of all Squares
BoardsArray getBoardsFromInput(char* inputPath) {
    // Try to open the inputFile in read mode
    FILE* inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) {
        throwFileError("Cannot open input file");
    }

    // Reads the number of boards
    int totalBoards;
    fscanf(inputFile, "%d", &totalBoards);

    // Creates a new array of Boards with the given number
    BoardsArray newBoards = createBoardsArray(totalBoards);

    // Reads all boards
    for (int b = 0; b < totalBoards; b++) {
        // Get number of rows and columns
        int rows, columns;
        if (fscanf(inputFile, "%d %d", &rows, &columns) != 2) {
            throwFileError("Some boards have invalid dimensions");
        }

        // Creates a new Board with the given dimensions
        Board newBoard = createBoard(rows, columns);

        // Read energy value in each column of each row
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                int energy;
                if (fscanf(inputFile, "%d", &energy) != 1) {
                    throwFileError("Some lines in input file are missing energy points");
                }
                newBoard.matrix[r][c].energy = energy;
            }
        }

        // Saves newBoard in newBoards array
        newBoards.boards[b] = newBoard;
    }

    // Closes inputFile
    fclose(inputFile);

    return newBoards;
}

void saveResultsOnOutput(char* outputPath, Energy* results, int resultsLength) {
    // Try to open the outputFile in write mode
    FILE* outputFile = fopen(outputPath, "w");
    if (outputFile == NULL) {
        throwFileError("Cannot open output file");
    }

    // Writes one result per line
    for (int i = 0; i < resultsLength; i++) {
        fprintf(outputFile, "%d\n", results[i]);
    }

    // Closes outputFile
    fclose(outputFile);
}