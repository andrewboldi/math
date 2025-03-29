#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>

mpz_t mersenne(mpz_t n) {
    mpz_t sum = 0;
    for (mpz_t k = 0; k < n - 1; k++) {
        sum += 1 / (1 << k);
    }
    return (((1 << n) * sum) - 1);
}

int main() {
    printf("2^5 - 1 = %d\n", mersenne(5));
    printf("2^7 - 1 = %d\n", mersenne(7));
    printf("2^11 - 1 = %d\n", mersenne(11));
    printf("2^111 - 1 = %d\n", mersenne(111));

    return 0;
}
