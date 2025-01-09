const input = require('fs').readFileSync(0)
.toString().trim().split('\n')

const len = Number(input[0]);
const arr = input[1].split(" ").map(Number);
console.log(Math.min(...arr), Math.max(...arr))