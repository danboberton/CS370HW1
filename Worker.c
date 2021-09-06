/*
Worker implementation file
Allocates memory in the heap, populates random arrays
Dan Butcher 9/6/21
*/

#include "Worker.h"

// Returns the ratio of he number of elements fully divisible
// by the divisor to the number of elements not fully divisible by the element.
float get_running_ratio(){

    int maxDivisibleElements = 0;
    int maxCountIteration = 0;
    int amountOfArrays = 0;
    int sizeOfCurrentArray = 0;
    int* heapArray = NULL;
    int devisor = 0;
    int divisabilityCount = 0;
    float runningRatioSum = 0.0;

    amountOfArrays = getRandomInRange(50, 100);

    // 2
    printf("[Worker]: Number of iterations is: %d\n", amountOfArrays);

    for (int i = 0; i < amountOfArrays; i++){

        // 3
        sizeOfCurrentArray = getRandomInRange(100, 150);
        heapArray = allocateArray(sizeOfCurrentArray);

        // 4
        populateArray(heapArray, sizeOfCurrentArray);

        // 5
        devisor = getRandomInRange(5, 15);
        divisabilityCount = get_divisibility_count(heapArray, sizeOfCurrentArray, devisor);

        // 6
        runningRatioSum += ((float)divisabilityCount / (float)(sizeOfCurrentArray - divisabilityCount));

        // 7
        if (divisabilityCount > maxDivisibleElements){
            maxDivisibleElements = divisabilityCount;
            maxCountIteration = (i + 1);
        }

        free(heapArray);
    }
    
    // 8
    printf("[Worker]: Iteration with maximum fully divisable elements is %d\n", maxCountIteration);

    //9
    return (runningRatioSum / amountOfArrays);
}

// Returns random number in a certain range
int getRandomInRange(int lowerBoundInclusive, int upperBoundExclusive){
    return (rand() % (upperBoundExclusive - lowerBoundInclusive) + lowerBoundInclusive);
}

// Returns pointer to heap location block of a certain size
int* allocateArray(int sizeOfArray){

    int* pointersArray = (int*)malloc(sizeof(int) * sizeOfArray);
    return pointersArray;
}

// Populates an array with random numbers
void populateArray(int* array, int sizeOfArray){

    for (int i = 0; i < sizeOfArray; i++){
        array[i] = getRandomInRange(1, 100);
    }
}

// Counts how many numbers in an int array are perfectly divisable by a number
int get_divisibility_count(int* array, int arraySize, int randomDividend){

    int result = 0;

    for (int i = 0; i < arraySize; i++){
        if (array[i] % randomDividend == 0){
            result++;
        }
    }

    return result;
}