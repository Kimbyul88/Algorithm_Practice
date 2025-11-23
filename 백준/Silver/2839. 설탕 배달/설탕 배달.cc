#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    scanf("%d", &n);
    int res = -1;
    for(int div= n/5;div>=0;div-=1){
       int remain = n - div*5;
       if(remain % 3 == 0){
           res = div + remain / 3;
           break;
       }
    }
    
    printf("%d", res);
    return 0;
}