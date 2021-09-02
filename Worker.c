// Worker.c
#include <stddef.h>

int main(int argc, char** argv) {

    size_t increment = 0;
    int** memArray = NULL;
    int* curInt = NULL;

    // Validate input
    if (argc < 1 || argc > 1 ){
        printf("\nInvalid Input");
    }

    // Create mem pointer array
    memArray = malloc(*argv[0] * sizeof(int*));

    // allocate memory
    curInt = memArray;

    for (;increment < *argv[0]; increment++){
        curInt = malloc(sizeof(int));
        *curInt = 
    }

    //deallocate memory


}

int random_in_range(int lower_bound, int upper_bound){
    return ((rand() % (upper_bound - lower_bound)) + lower_bound);
}

int get_divisibility_count(int *array, int arraySize, int randomDividend){
    return 0;
}

void workerPrint(char** string){

}