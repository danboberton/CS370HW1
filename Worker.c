// Worker.c
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {

    int** memArray = NULL;
    int* curInt = NULL;
    char* arg2 = argv[1]; 
    int numArray = atoi(arg2);

    // Validate input
    if (argc < 2 || argc > 2 ){
        printf("\n[Worker]: Invalid Input\n");
        return 0;
    }

    if (numArray <= 0){
        printf("\n[Worker]: Invalid Array Size\n");
        return 0;
    }
    

    // Create mem pointer array
    memArray = malloc(numArray * sizeof(int*));

    // allocate memory
    curInt = memArray;

    for (size_t increment = 0;increment < numArray; increment++){
        curInt = malloc(sizeof(int));
        *curInt = random_in_range(1, 99);
        curInt = curInt+1;
    }

    // print memory
   curInt = memArray;

    for (size_t increment = 0;increment < numArray; increment++){
        printf(*curInt);
        curInt = curInt + 1;
    } 

    //deallocate memory

return 1;
}

int random_in_range(int lower_bound, int upper_bound){
    return ((rand() % (upper_bound - lower_bound)) + lower_bound);
}

int get_divisibility_count(int *array, int arraySize, int randomDividend){
    return 0;
}

void workerPrint(char** string){

}