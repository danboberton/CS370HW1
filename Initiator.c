#include <stdlib.h>
#include <stdio.h>
#include "Worker.h"


// TODO: Implement
int validInput(int argc, char** argv) {
    return 0;
}

int setSeed(int seed){

    srand(seed);
    printf("[Initiator]: With seed: %d\n", seed);
    return 0;
}

int main(int argc, char** argv){

    float runningRatio = 0;

    // input validation
    if (validInput(argc, argv)){
        printf("[Initiator]: Invalid Input");
        return 1;
    }

    // setting seed whose value is passed as an arg
    setSeed(atoi(argv[1]));

    runningRatio = get_running_ratio();

    printf("[Initiator]: Average ratio is: %f\n", runningRatio);
}