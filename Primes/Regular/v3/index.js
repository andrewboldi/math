var a, b, i, ans;
const RelativelyPrime = (a, b) => { // Assumes a, b > 0
   return (a < b) ? RelativelyPrime(b, a) : !(a % b) ? (b == 1) : RelativelyPrime (b, a % b);
}

const Totient = (n) => {
    ans = 0;
    for (i = 1; i < n; i++) {
        if (RelativelyPrime(i, n)) ans += 1;
    }
    return ans;
}

const isPrime = (n) => {
    a = (n >> 1);
    b = a + 1;
    if (Totient(n) == a << 1) return true;
    return false;
}

if (process.argv.length > 3) {
    console.log("Too many arguments");
    process.exit(-1);
}

if (process.argv[2] == undefined || !!/\D/.test(process.argv[2])) {
    console.log("Must enter a valid number as an argument");
    process.exit(-1);
} 

console.log(isPrime(parseInt(process.argv[2])));
