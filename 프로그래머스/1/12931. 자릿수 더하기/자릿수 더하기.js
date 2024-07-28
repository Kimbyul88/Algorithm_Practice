function solution(n)
{
    return (""+n).split("").reduce((acc,cur)=>{
        return acc+Number(cur)
    },0);
}