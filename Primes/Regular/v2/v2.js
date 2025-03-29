const fs = require("fs")

let primes, lim, g, h, j

const calculatePrimes = (max) => {
    lim = Math.floor(Math.sqrt(max))
    primes = Array(max).fill(true)

    for (g = 0; g <= lim; g++) {
        if ((primes[g]) == false) continue
        if (g <= 1) {
            primes[g] = false
            continue
        }
        for (h = g * g; h <= max; h += g) {
            if ((primes[h]) == false) continue
            primes[h] = false
        }
        if (g % 100000 == 0) console.log(g)
    }
    

}


var f = fs.createWriteStream('n100m.txt')
f.on('error', function(err) { /* error handling */ })
calculatePrimes(100000000)
console.log("done with primes")
console.log("beginning file save...")
j = 0
primes.forEach(prime => {
    if (prime) f.write(j + "\n")
    j++
    if (j % 100000 == 0) console.log(j)
})
f.end();
console.log("file write complete!")