const BigNumber = require("bignumber.js");
const fs = require("fs");

const fib = (n, memo={}) => {
  if (n in memo) return memo[n];
  if (n <= 2) return 1;
  memo[n] = BigNumber(fib(n - 1, memo)).plus(BigNumber(fib(n - 2, memo)));
  if (Object.keys(memo).length > 3) memo[n - 3] = undefined;
  return memo[n];
}

var writerStream = fs.createWriteStream('1m.txt');
memo = {};
for (var v=1; v<=1000000;v++) {
    var val = fib(v, memo).toFixed();
    console.log(v);
    var data = val + "\n";
    writerStream.write(data,'UTF8');
}
writerStream.end();
writerStream.on('finish', function() {
   console.log("Write completed.");
});

