#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Problem 5
int main() {
    int number = 1;
    bool go = true;
    while (go) {
        for (int i = 20; i > 1; i--) {
            if (fmod((float)number, (float)i) != 0) break;
            if (i == 2) go = false;
        }
        number++;
    }
    printf("Lowest number divisible by 1 to 20: %d\n", number);
    return 0;
}