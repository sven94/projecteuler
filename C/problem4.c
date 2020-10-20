#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Problem 4

void push(int **arr, int *used, int *size, int value){
    if(*used >= *size){
        *size *= 2;
        *arr = realloc(*arr, *size * sizeof(int));
    }
    (*arr)[*used] = value;
    *used += 1;
}

bool isPalindrome(int x, int y) {
    int size = 2;
    int used = 0;

    int *digits = malloc(size * sizeof(int));

    int product = x * y;

    printf("%d * %d = %d\n", x, y, product);

    while (product) {
        push(&digits, &used, &size, product % 10);
        product /= 10;
    }

    int checks;
    if ((used) % 2 == 0) {
        checks = used / 2;
    }
    else {
        checks = (used) / 2;
    }

    for (int i = 0; i < checks; i++) {
        if (digits[i] != digits[used - 1 - i]) {
            free(digits);
            return false;
        }
    }
    free(digits);
    return true;
}

int findMaxPalindrome(min, max) {
    int result;
    for (int i = min; i < max; i++) {
        for (int j = min; j < max; j++) {
            if (isPalindrome(i, j)) {
                result = i * j;
            }
        }
    }
    return result;
}

int main() {
    printf("Biggest palindrome: %d\n", findMaxPalindrome(100, 1000));
}