#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gmp.h>
#include <cuda_runtime.h>

#define MAX_PRIME 1000000000 // 1 billion
#define BLOCK_SIZE 256

__global__ void sieve_kernel(bool* is_prime) {
    unsigned int i = blockIdx.x * blockDim.x + threadIdx.x;
    unsigned int stride = gridDim.x * blockDim.x;

    for (i; i <= MAX_PRIME; i += stride) {
        if (is_prime[i]) {
            for (unsigned int j = i * i; j <= MAX_PRIME; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    // Allocate memory on the CPU
    bool* is_prime = (bool*)calloc(MAX_PRIME + 1, sizeof(bool));

    // Allocate memory on the GPU
    bool* d_is_prime;
    cudaMalloc((void**)&d_is_prime, (MAX_PRIME + 1) * sizeof(bool));

    // Mark all numbers as prime initially
    for (mpz_t i; mpz_init(i), mpz_set_ui(i, 2), mpz_cmp_ui(i, MAX_PRIME) <= 0; mpz_add_ui(i, i, 1)) {
        is_prime[mpz_get_ui(i)] = true;
    }
    mpz_clear(i);

    // Copy the initial `is_prime` bitmap to the GPU
    cudaMemcpy(d_is_prime, is_prime, (MAX_PRIME + 1) * sizeof(bool), cudaMemcpyHostToDevice);

    // Launch the CUDA kernel to perform the Sieve of Eratosthenes
    dim3 grid_size((MAX_PRIME + BLOCK_SIZE - 1) / BLOCK_SIZE, 1, 1);
    dim3 block_size(BLOCK_SIZE, 1, 1);
    sieve_kernel<<<grid_size, block_size>>>(d_is_prime);
    cudaDeviceSynchronize();

    // Copy the updated `is_prime` bitmap back to the CPU
    cudaMemcpy(is_prime, d_is_prime, (MAX_PRIME + 1) * sizeof(bool), cudaMemcpyDeviceToHost);

    // Write the prime numbers to a file
    FILE* fp = fopen("primes_up_to_1_billion.txt", "w");
    for (mpz_t i; mpz_init(i), mpz_set_ui(i, 2), mpz_cmp_ui(i, MAX_PRIME) <= 0; mpz_add_ui(i, i, 1)) {
        if (is_prime[mpz_get_ui(i)]) {
            fprintf(fp, "%lu\n", mpz_get_ui(i));
        }
    }
    mpz_clear(i);
    fclose(fp);

    // Clean up
    free(is_prime);
    cudaFree(d_is_prime);
    return 0;
}
