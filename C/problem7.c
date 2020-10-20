#include <stdio.h>
#include <math.h> 
#include <stdbool.h>

// Problem 7

bool isPrime(long number) {
    for (int i = 2; i < number; i++) {
        if (fmod(number, i) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int counter = 0;
    int prime = 2;
    
    while (counter < 10001) {
        if (isPrime(prime)) counter++;
        prime++;
    }

    printf("10001st prime number %d\n", prime);
}