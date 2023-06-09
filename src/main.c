/*============================================================
    #define SUBJECT "Algoritmos e Estruturas de Dados III"
    #define WORK "Trabalho Pŕatico 2 - Harry Potter"
    #define PROFESSOR "Leo Rocha"
    #define STUDENTS ["Davi dos Reis", "Gabriel de Paula"]
============================================================*/

#include <stdio.h>
#include <stdlib.h>

#include "../include/args.h"
#include "../include/boardio.h"
#include "../include/boardlib.h"
#include "../include/strategyDFS.h"
#include "../include/strategyDP.h"
#include "../include/time.h"

int main(int argc, char* argv[]) {
    // User must enter strategy and inputPath in command line
    int strategy;
    char* inputPath;
    getArgs(&strategy, &inputPath, argc, argv);

    // Get all Boards from inputPath
    BoardsArray inputBoards = getBoardsFromInput(inputPath);

    // Allocates results array
    Energy* results = (Energy*)malloc(sizeof(Energy) * inputBoards.length);

    // Starts time monitoring
    printf("\nElapsed times (Strategy %d)\n\n", strategy);
    Time startReal = getRealTime();
    Time startCPU = getCpuTime();

    // Runs strategy to find result in all boards
    for (int i = 0; i < inputBoards.length; i++) {
        // Stores the result based on selected strategy
        switch (strategy) {
            case 1:
                results[i] = strategyDFS(&inputBoards.boards[i], 1);
                break;
            case 2:
                results[i] = strategyDynamic(&inputBoards.boards[i]);
                break;
            default:
                results[i] = strategyDFS(&inputBoards.boards[i], 0);
                break;
        }

        // Prints Board data and result
        printf("Board %d (%dx%d)\n", i + 1, inputBoards.boards[i].rows, inputBoards.boards[i].columns);
        printf("Minimum Life = %d\n", results[i]);

        // Ends time monitoring
        Time endReal = getRealTime();
        Time endCPU = getCpuTime();
        printElapsedTime("Real Time", startReal, endReal);
        printElapsedTime("CPU Time ", startCPU, endCPU);
        printf("\n");

        // Resets timer
        startReal = endReal;
        startCPU = endCPU;
    }

    // Saves results on outputFile
    saveResultsOnOutput("saida.txt", results, inputBoards.length);

    // Deallocates inputBoards and results
    freeBoardsArray(&inputBoards);
    free(results);

    return 0;
}