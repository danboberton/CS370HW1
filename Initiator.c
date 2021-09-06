

#include <stdlib.h>
#include <stdio.h>
#include "Worker.h"


// TODO: Implement
int validInput(int argc, char** argv) {
    if (argc < 2){
        return 1;
    }

    if (atoi(argv[1]) < 0){
        return 1;
    }

    return 0;
}

void setSeed(int seed){

    srand(seed);
    printf("[Initiator]: With seed: %d\n", seed);

}

int main(int argc, char** argv){

    float runningRatio = 0;
    int seed = 0;

    // input validation
    if (validInput(argc, argv)){
        printf("[Initiator]: Invalid Input");
        return 1;
    }

    seed = atoi(argv[1]);

    // setting seed whose value is passed as an arg
    setSeed(seed);

    runningRatio = get_running_ratio();

    printf("[Initiator]: Average ratio is: %f\n", runningRatio);
}