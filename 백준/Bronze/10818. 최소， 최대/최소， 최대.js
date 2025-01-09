const input = require('fs').readFileSync(0)
.toString().trim().split('\n')

const len = Number(input[0]);
const arr = input[1].split(" ").map(Number);
const sorted = arr.sort((a,b)=>{
    return a-b
});
console.log(`${sorted[0]} ${sorted[len-1]}`)