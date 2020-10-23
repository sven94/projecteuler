#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


// Problem 10
// CUDA potential

#define N 1000

bool isPrime(long number) {
    for (int i = 2; i < number; i++) 
        if (fmod((double)number, (double)i) == 0) return false;
    return true;
}

int main() {

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int sum = 0;
    for (int i = 2; i < N; i++)
    {
        if (isPrime(i)){
            sum += i;
        }
    }
    printf("Sum of primes below %d = %d\n", N, sum);

    end = clock();
    cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;

    printf("%f\n", cpu_time_used);

    return 0;
}