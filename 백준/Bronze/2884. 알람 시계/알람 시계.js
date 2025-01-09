const input = require('fs').readFileSync('/dev/stdin')
.toString().trim().split(" ").map(Number)

//24hrs 24*60 mins = 1440 mins
// 10 : 30 = 10*60 + 30 = 630
// 0: 30 - 45min -> if (min<45) {1440 - (45-min)} 

if(input[1]<45){
    if(input[0]!==0)
        console.log(`${(24+input[0])%24-1} ${60-(45-input[1])}`)
    else 
        console.log(`${23} ${60-(45-input[1])}`)
}
else{
    console.log(`${input[0]} ${input[1]-45}`)
}