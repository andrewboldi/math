#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <gmp.h>

// Function to check if a number is prime using GMP
int is_prime(mpz_t n) {
    int result;
    result = mpz_probab_prime_p(n, 25); // Probability-based primality test
    return result;
}

// Function to generate primes up to a given limit using Sieve of Eratosthenes
void generate_primes(uint64_t limit, char* filename) {
    mpz_t n;
    mpz_init(n);
    
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        exit(1);
    }

    // Chunk size for memory allocation
    const uint64_t chunk_size = 1000000; // 1 million

    // Progress bar setup
    const int barWidth = 70;
    printf("Generating primes: [");
    fflush(stdout);

    for (int i = 0; i < barWidth; ++i) {
        printf(" ");
    }
    printf("]\r");
    fflush(stdout);

    for (uint64_t start = 2; start <= limit; start += chunk_size) {
        uint64_t end = (start + chunk_size < limit) ? start + chunk_size : limit;

        char* sieve = calloc(end - start + 1, sizeof(char));
        if (!sieve) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        for (uint64_t p = 2; p * p <= end; ++p) {
            if (!sieve[p - start]) {
                for (uint64_t i = p * p; i <= end; i += p) {
                    sieve[i - start] = 1;
                }
            }
        }

        // Write primes to file
        for (uint64_t p = (start == 2) ? 2 : start + 1; p <= end; ++p) {
            if (!sieve[p - start]) {
                mpz_set_ui(n, p);
                if (is_prime(n)) {
                    gmp_fprintf(file, "%Zd\n", n);
                }
            }
        }

        // Update progress bar
        int progress = (end * barWidth) / limit;
        printf("\rGenerating primes: [");
        for (int i = 0; i < progress; ++i) {
            printf("=");
        }
        for (int i = progress; i < barWidth; ++i) {
            printf(" ");
        }
        printf("]");
        fflush(stdout);

        free(sieve);
    }

    // Cleanup
    fclose(file);
    mpz_clear(n);

    printf("\nPrimes generated successfully.\n");
}

int main() {
    uint64_t limit = 1000000000000; // 1 trillion
    char* filename = "trillion_primes.txt";

    generate_primes(limit, filename);

    return 0;
}

