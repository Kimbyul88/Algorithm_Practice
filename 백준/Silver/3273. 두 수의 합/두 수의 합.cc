#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int num1 = *(int*)a;
    int num2 = *(int *)b;

    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}


int main(void){
    int n, x;
    scanf("%d", &n);
    int* num_arr = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d ", &num_arr[i]);
    }
    scanf("%d", &x);
    //
    
    //sorting : quick sort
    //배열, 사이즈, 타입 사이즈, 비교 함수
    qsort(num_arr, n, sizeof(int), compare);
    
    int count=0;
    int start = 0;
    int end = n-1;
    
    while(start<end){
        if(num_arr[start]+num_arr[end]>x){
            end--;
        }else if(num_arr[start]+num_arr[end] == x){
            start++; end--;
            count++;
        }else{
            start++;
        }
    }
    
    printf("%d", count);
    free(num_arr);
    
    return 0;
}