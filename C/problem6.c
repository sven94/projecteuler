#include <stdio.h>
#include <math.h> 

// Problem 6
// CUDA potential

int main() {
    int n = 100;
    int squareOfSums = 0;
    int sumOfSquares = 0;

    for (int i = 1; i <= n; i++) {
        squareOfSums += i;
        sumOfSquares += pow(i, 2);
    }
    squareOfSums = pow(squareOfSums, 2);
    printf("Difference between square of sums and sum of squares: %d\n", squareOfSums - sumOfSquares);
}