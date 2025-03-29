let a, b, c, f, i, temp;
// let s;

const BigNumber = require("bignumber.js");
const fs = require("fs");


var writerStream = fs.createWriteStream('1m.txt');

const fib = (n) => {
    a = 1;
    b = 1;
    i = 0;
    while (i <= n) {
        temp = BigNumber(b);
/*        s = a % 7;
        if (s == 0) {
            s = 7;
        }
*/
        writerStream.write(a.toFixed() + "\n",'UTF8');
        c = BigNumber(a).plus(BigNumber(b));
        b = c;
        a = temp;
        i++;
        if (i % 10000 == 0) {
            console.log(i);
            writerStream.end();
        }
    }
    return c;
}

console.log(fib(1000000));

writerStream.end();
writerStream.on('finish', function() {
   console.log("Write completed.");
});
