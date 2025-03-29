var fs = require("fs");
var primes = [2];

function isPrime(num) {
    return primes.every(value => {
        if (Math.sqrt(num) >= value) {
            if (num % value == 0) {
                return false;
            }
        }
        return true;
    });
}

for (var j=3; j<=10000000; j+=2) {
  if ((j+1) % 1000000 == 0) {
    console.log((j+1)/10000000 + "%");
  }
  if (isPrime(j)) {
    primes.push(j);
  }
}

var file = fs.createWriteStream('1m.txt');
file.on('error', function(err) { /* error handling */ });
primes.forEach(function(v) { file.write(v + '\n'); });
file.end();
