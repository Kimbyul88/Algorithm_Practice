const input = require('fs').readFileSync('/dev/stdin')
.toString().trim().split('\n').map(Number)

//일단 두번째 숫자를 하나하나 쪼갠다. 
const second = [...input[1].toString()].map(Number).reverse();
//곱해서 출력 
second.forEach((el,key)=>{
    console.log(el*input[0]);
})
//마지막 출력
console.log(input[0]*input[1]);

