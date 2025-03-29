function isPrime(num) {
  for (var i = 2; i <= Math.sqrt(num); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

for (var j = 6; j < 10000; j += 6) {
  console.log(isPrime(j - 1) * (j - 1) && isPrime(j + 1) * (j + 1));
  /*  if (isPrime(j - 1) * (j - 1) != 0 && isPrime(j + 1) * (j + 1) != 0)
    console.log(isPrime(j - 1) * (j - 1), isPrime(j + 1) * (j + 1)); */
}
