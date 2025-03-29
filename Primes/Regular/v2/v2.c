// This is a second version of calculating primes under a certain number
// using the Sieve of Eratosthenes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int g, h, j;
FILE *f;
long long int size = 5000000000;
char primes[5000000000];

void fail() {
    printf("Memory could not be allocated :(");
    exit(EXIT_FAILURE);
}

void calculatePrimes() {
//    primes = (bool *) malloc(size * sizeof(bool));
    
    printf("beginning allocation...\n");
    for (int y = 0; y < size; y++) {
        if (y+1 % 1000000000 == 0) printf("Done with another 1 billion\n");
        primes[y] = 1;
    }

    printf("Done allocating memory\n");

    printf("Starting prime function...\n");
    for (g = 3; g <= floor(sqrt(size)); g+=2) {
        if (primes[g] == 0) continue;

        for (h = g * g; h <= size; h += g) {
            if (primes[h] == 0 || h % 2 == 0) continue;
            primes[h] = 0;
        }
    }

}



int main () {
    printf("starting program...\n");
    calculatePrimes();
    printf("Done calculating primes!\n\n");

    f = fopen("10b.txt", "a");
    printf("Beginning write to file...\n");
    for (int j=3; j < sizeof(primes); j+=2) {
        if (primes[j] == 1) {
            fprintf(f, "%d\n", j);
        }
    }
    fclose(f);
    printf("file write complete!\n\n");


    _exit;
}
