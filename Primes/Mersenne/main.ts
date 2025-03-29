const BigNumber = require("bignumber.js");

mersenne(let n: number) {
    let sum: number = 0;
    for (k: number = 0; k < n - 1; k++) {
        sum += 1 / (1 << k);
    }
    return (((1 << n) * sum) - 1);
}
