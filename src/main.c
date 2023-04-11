#include <stdio.h>
#include <stdlib.h>

#include "../include/args.h"
#include "../include/boardio.h"
#include "../include/boardlib.h"

int main(int argc, char* argv[]) {
    // User must enter strategy and inputPath in command line
    int strategy;
    char* inputPath;
    getArgs(&strategy, &inputPath, argc, argv);

    // Get all Boards from inputPath
    BoardsArray inputBoards = getBoardsFromInput(inputPath);
    for (int i = 0; i < inputBoards.length; i++) {
        printf("Board %d\n", i + 1);
        printBoard(&inputBoards.boards[i]);
    }

    return 0;
}