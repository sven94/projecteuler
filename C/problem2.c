#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Problem 2

void push(int **arr, int *used, int *size, int value){
    if(*used > *size){
        *size *= 2;
        *arr = realloc(*arr, *size * sizeof(int));
    }
    (*arr)[*used] = value;
    *used += 1;
}

void withArray(int limit) {
    int size = 2;
    int used = 0;

    int *arr = malloc(size * sizeof(int));

    push(&arr, &used, &size, 1);
    push(&arr, &used, &size, 2);

    int nextFib = 0;
    int index = 2;

    while (nextFib < limit) {
        push(&arr, &used, &size, arr[index - 1] + arr[index - 2]);
        index += 1;
        nextFib = arr[index - 1] + arr[index - 2];
    }

    int sum = 0;
    for (int i = 0; i < used; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }

    printf("Sum of even-valued Fibonacci numbers under 4 million: %d\n", sum);
}

void withoutArray(int limit) {
    int sum = 2;

    int secondLatest = 1;
    int latest = 2;
    int nextFib = 3;

    while (nextFib < limit) {
        if (nextFib % 2 == 0) {
            sum += nextFib;
        }
        secondLatest = latest;
        latest = nextFib;
        nextFib = latest + secondLatest;
    }
    printf("Sum of even-valued Fibonacci numbers under 4 million: %d\n", sum);
}

int main() {
    time_t start = time(NULL);

    int limit = 4000000;

    withoutArray(limit);

    time_t end = time(NULL);
    printf("Time in seconds: %ld\n", end - start);

    return 0;
}