/*
Worker Header file
Dan Butcher 9/6/21
*/

#include <stdio.h>
#include <stdlib.h>

float get_running_ratio();
int getRandomInRange(int lowerBoundInclusive, int upperBoundExclusive);
int* allocateArray(int sizeOfArray);
void populateArray(int* array, int sizeOfArray);
int get_divisibility_count(int* array, int arraySize, int randomDividend);
