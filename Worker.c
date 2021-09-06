#include "Worker.h"
#include <stdio.h>
#include <stdlib.h>

float get_running_ratio(){

    int maxDivisibleElements = 0;
    int maxCountIteration = 0;
    int amountOfArrays = 0;
    int* heapArray = NULL;
    int devisor = 0;
    int divisabilityCount = 0;
    float runningRatioSum = 0.0;

    amountOfArrays = getRandomInRange(50, 100);

    printf("[Worker]: Number of iterations is: %d\n", amountOfArrays);

    for (int i = 0; i < amountOfArrays; i++){

        heapArray = allocateArray(amountOfArrays);
        populateArray(heapArray, amountOfArrays);

        devisor = getRandomInRange(5, 15);

        divisabilityCount = get_divisibility_count(heapArray, amountOfArrays, devisor);

        // 6
        runningRatioSum += ((float)divisabilityCount / (float)amountOfArrays);

        // 7
        if (divisabilityCount > maxDivisibleElements){
            maxDivisibleElements = divisabilityCount;
            maxCountIteration = i;
        }

        free(heapArray);

    }
    
    // 8
    printf("[Worker]: Iteration with maximum fully divisable elements is %d\n", maxCountIteration);

    //9
    return (runningRatioSum / amountOfArrays);

}

int getRandomInRange(int lowerBoundInclusive, int upperBoundExclusive){

    return (rand() % (upperBoundExclusive - 1) + lowerBoundInclusive);
    
}

int* allocateArray(int sizeOfArray){

    int* pointersArray = (int*)malloc(sizeof(int) * sizeOfArray);

    return pointersArray;

}

void populateArray(int* array, int sizeOfArray){

    for (int i = 0; i < sizeOfArray; i++){
        array[i] = getRandomInRange(1, 100);
    }
}

int get_divisibility_count(int* array, int arraySize, int randomDividend){

    int result = 0;

    for (int i = 0; i < arraySize; i++){
        if (array[i] % randomDividend == 0){
            result++;
        }
    }

    return result;
}