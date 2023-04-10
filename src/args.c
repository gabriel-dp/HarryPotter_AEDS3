#include "../include/args.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stops the program if the args have an error
void throwArgsError(char* message) {
    printf("ARGS ERROR - %s\n", message);
    exit(EXIT_FAILURE);
}

// Receives strategy and inputPath data from user in command line
void getArgs(int* strategy, char** inputPath, int argc, char* argv[]) {
    // Checks if quantity of args is equal to 3
    if (argc != 3) {
        throwArgsError("Correct usage: ./tp2 {strategy} {inputPath}");
    }

    // Reads and validates strategy integer value
    *strategy = atoi(argv[1]);
    if (*strategy != 1 && *strategy != 2) {
        throwArgsError("Strategy must be 1 for Recursive or 2 for Dynamic");
    }

    // Reads inputPath string
    *inputPath = argv[2];
}