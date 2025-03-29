#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <gmp.h>

// Function to check if a number is prime using GMP
int is_prime(mpz_t n) {
    return mpz_probab_prime_p(n, 25); // Probability-based primality test
}

// Function to generate primes up to a given limit using Sieve of Eratosthenes
void generate_primes(mpz_t limit, char* filename) {
    mpz_t n;
    mpz_init(n);
    
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        exit(1);
    }

    mpz_t chunk_size;
    mpz_init_set_ui(chunk_size, 1000000); // 1 million

    mpz_t start;
    mpz_init_set_ui(start, 2);

    mpz_t end;
    mpz_init(end);

    mpz_t progress;
    mpz_init(progress);

    // Progress bar setup
    const int barWidth = 70;
    printf("Generating primes: [");
    fflush(stdout);

    for (int i = 0; i < barWidth; ++i) {
        printf(" ");
    }
    printf("]\r");
    fflush(stdout);

    while (mpz_cmp(start, limit) <= 0) {
        mpz_add(end, start, chunk_size);
        if (mpz_cmp(end, limit) > 0)
            mpz_set(end, limit);

        char* sieve = calloc(mpz_get_ui(chunk_size), sizeof(char));
        if (!sieve) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        for (mpz_set_ui(n, 2); mpz_cmp(n, end) <= 0; mpz_nextprime(n, n)) {
            mpz_t p_square;
            mpz_init(p_square);
            mpz_mul(p_square, n, n);

            for (mpz_set(n, p_square); mpz_cmp(n, end) <= 0; mpz_add(n, n, p_square)) {
                mpz_t index;
                mpz_init(index);
                mpz_sub(index, n, start);
                sieve[mpz_get_ui(index)] = 1;
                mpz_clear(index);
            }

            mpz_clear(p_square);
        }

        // Write primes to file
        for (mpz_set(n, start); mpz_cmp(n, end) <= 0; mpz_add_ui(n, n, 1)) {
            if (!sieve[mpz_get_ui(mpz_sub(n, n, start))]) {
                if (is_prime(n)) {
                    gmp_fprintf(file, "%Zd\n", n);
                }
            }
        }

        // Update progress bar
        mpz_mul(progress, end, chunk_size);
        mpz_tdiv_q(progress, progress, limit);
        int bar_position = mpz_get_ui(progress) * barWidth;
        printf("\rGenerating primes: [");
        for (int i = 0; i < bar_position; ++i) {
            printf("=");
        }
        for (int i = bar_position; i < barWidth; ++i) {
            printf(" ");
        }
        printf("]");
        fflush(stdout);

        free(sieve);
        mpz_add(start, start, chunk_size);
    }

    // Cleanup
    fclose(file);
    mpz_clears(n, chunk_size, start, end, progress, NULL);

    printf("\nPrimes generated successfully.\n");
}

int main() {
    mpz_t limit;
    mpz_init_set_str(limit, "1000000000000", 10); // 1 trillion
    char* filename = "trillion_primes.txt";

    generate_primes(limit, filename);

    return 0;
}

