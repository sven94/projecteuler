#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Problem 1

/**
 * Dynamically add elements to array. When the size of the array exceeds the capacity of the allocated memory, 
 * reallocate the memory to be twice as large. Note that size and capacity are passed as pointers, so that
 * the underlying value can be changed in this function. Arrays are always passed as pointers.
*/
void push(int **arr, int *used, int *size, int value){
    if(*used > *size){
        *size *= 2;
        *arr = realloc(*arr, *size * sizeof(int));
    }
    (*arr)[*used] = value;
    *used += 1;
}

bool multiple(int i) {
    if (i % 3 == 0 || i % 5 == 0) {
        return true;
    } 
    else {
        return false;
    }
}

int main() {
    time_t start = time(NULL);

    int size = 2;
    int used = 0;

    /*
    * C doesn't come with dynamic arrays, so we have to create them ourselves. First we just need
    * to allocate a memory block with an initial capacity of 8 bytes (int = 4 bytes) .
    */
    int *arr = malloc(size * sizeof(int));

    int sum = 0;

    for (int i = 0; i < 1000; i++) {
        if (multiple(i)) {
            sum += i;
        }
    }

    printf("Sum of all multiples of 3 or 5: %d\n", sum);

    time_t end = time(NULL);

    printf("Time in seconds: %ld\n", end - start);

    return 0;
}