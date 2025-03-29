#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <gmp.h>
#include <string.h>

#define LIMIT 1000000000ULL
#define SQRT_LIMIT 31623

static inline uint64_t isqrt(uint64_t n) {
    __asm__ ("bsrq %1, %%rax\n\t"
             "shrq $1, %%rax\n\t"
             "addq $0x3FF0000000000000, %%rax\n\t"
             "movq %%rax, %0"
             : "=r"(n)
             : "r"(n)
             : "rax");
    return n;
}

int main() {
    mpz_t prime;
    mpz_init(prime);

    FILE *out = fopen("primes.txt", "w");
    if (out == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    uint64_t *sieve = calloc(SQRT_LIMIT / 64 + 1, sizeof(uint64_t));
    if (sieve == NULL) {
        printf("Error allocating memory\n");
        fclose(out);
        return 1;
    }
    memset(sieve, 0xFF, (SQRT_LIMIT / 64 + 1) * sizeof(uint64_t));

    for (uint64_t i = 3; i <= SQRT_LIMIT; i += 2) {
        if (sieve[i / 64] & (1ULL << (i % 64))) {
            for (uint64_t j = i * i; j <= LIMIT; j += 2 * i) {
                sieve[j / 64] &= ~(1ULL << (j % 64));
            }
        }
    }

    mpz_set_ui(prime, 2);
    gmp_fprintf(out, "%Zd\n", prime);

    for (uint64_t i = 3; i <= LIMIT; i += 2) {
        if (sieve[i / 64] & (1ULL << (i % 64))) {
            mpz_set_ui(prime, i);
            gmp_fprintf(out, "%Zd\n", prime);
        }
    }

    free(sieve);
    mpz_clear(prime);
    fclose(out);

    return 0;
}
