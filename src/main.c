#include <stdio.h>
#include <stdlib.h>

#include "../include/args.h"

int main(int argc, char* argv[]) {
    // User must enter data in command line
    int strategy;
    char* inputPath;
    getArgs(&strategy, &inputPath, argc, argv);

    return 0;
}