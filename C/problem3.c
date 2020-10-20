#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <math.h>

// Problem 3

int findNextPrime(int prime);
bool isPrime(long number);

int main () {
    long remainder = 600851475143;
    int largestPrime = 2;

    printf("Prime factors: ");

    // Keep dividing remainder with prime numbers
    while (remainder > 1) {
        if (isPrime(remainder)) {
            // The remainder is a prime number, so there's no need trying to divide it
            largestPrime = remainder;
            break;
        }
        double division = (double)remainder / (double)largestPrime;
        if (fmod(division, 1.0) == 0) {
            // Division works, so actually apply the division and continue with dividing remainder
            printf("%d,", largestPrime);
            remainder /= largestPrime;
        }
        else {
            // Division doesn't work, so use the next prime number
            largestPrime = findNextPrime(largestPrime);
        }
    }
    printf("%d", largestPrime);
    printf("\nLargest prime factor: %d\n", largestPrime);
    return 0;
}

/**
 * Find the first next (higher) prime number based on another number.
*/
int findNextPrime(int prime) {
    int result;
    for (int i = prime + 1; i < INT_MAX; i++) {
        if (isPrime(i)) {
            result = i;
            break;
        }
    }
    return result;
}

/**
 * Check if a number is a prime number by trying to divide it by all numbers below it.
*/
bool isPrime(long number) {
    for (int i = 2; i < number; i++) {
        double division = (double)number / (double)i;
        if (fmod(division, 1) == 0) {
            return false;
        }
    }
    return true;
}