#include <bits/stdc++.h>

_Bool isPrime(int num) {
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
    for (int j = 6; j < 10000; j += 6) {
      printf("%d: %d\n", j, isPrime(j - 1) * (j - 1) && isPrime(j + 1) * (j + 1));
    }
    return 0;
}
