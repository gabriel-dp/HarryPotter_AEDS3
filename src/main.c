#include <stdio.h>

#include "../include/args.h"
#include "../include/boardio.h"
#include "../include/boardlib.h"
#include "../include/strategy.h"
#include "../include/time.h"

int main(int argc, char* argv[]) {
    // User must enter strategy and inputPath in command line
    int strategy;
    char* inputPath;
    getArgs(&strategy, &inputPath, argc, argv);

    // Get all Boards from inputPath
    BoardsArray inputBoards = getBoardsFromInput(inputPath);

    // Starts time monitoring
    Time startReal = getRealTime();
    Time startCPU = getCpuTime();

    // Run strategy1 to find result of all boards
    for (int i = 0; i < inputBoards.length; i++) {
        printf("\nBoard %d - |%d|\n", i + 1, strategy1(&inputBoards.boards[i]));

        // Ends time monitoring
        Time endReal = getRealTime();
        Time endCPU = getCpuTime();
        printElapsedTime("Real Time", startReal, endReal);
        printElapsedTime("CPU Time", startCPU, endCPU);

        // Resets timer
        startReal = endReal;
        startCPU = endCPU;
    }

    return 0;
}