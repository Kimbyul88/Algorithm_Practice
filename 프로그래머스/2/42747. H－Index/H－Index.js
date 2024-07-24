function solution(citations) {
    var if_returned = false;
    for(i=citations.length;i>=1;i--){
        if(citations.filter((item)=>item>=i).length>=i){
            return i;
        }
            
    }
    if(!if_returned) return 0;
}