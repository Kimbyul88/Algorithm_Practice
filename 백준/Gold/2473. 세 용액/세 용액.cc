#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int comp(const void* a, const void* b){
    int* p = (int*) a;
    int* q = (int*) b; 
    
    if(*p < *q) return -1;
    if(*p > *q) return 1;
    return 0;
}

int main(void){
    int num;
    scanf("%d", &num);
    
    int* arr = (int*)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
        scanf("%d", &arr[i]);
    }
    
    //-2 6 -97 -6 98
    //1. 정렬
    //-97 -6 -2 6 98
    qsort(arr, num, sizeof(int), comp);
    
    //모든 용액이 한 속성일 경우
    if(arr[num - 1] < 0) {
        printf("%d %d %d", arr[num-3], arr[num-2], arr[num-1]);
        free(arr);
        return 0;
    }
    if(arr[0] >= 0) {
        printf("%d %d %d", arr[0], arr[1], arr[2]);
        free(arr);
        return 0;
    }
    
    int idx1 = 0, idx2 = 1, idx3 = 2;
    long long final_sum = LLONG_MAX;
    
    //2. 한 개 고정
    for(int i = 0; i < num - 2; i++){
        //int current_sum = INT_MIN;
        int j = i + 1;
        int k = num - 1;
        
        while(j < k){
            long long current_sum = (long long)arr[i] + arr[j] + arr[k];
            
            //current의 절댓값이 더 작으면 바꾼다. 
            if(llabs(current_sum)<llabs(final_sum)){
                final_sum = current_sum;
                idx1 = i;
                idx2 = j;
                idx3 = k;
            }
            
            if (current_sum == 0) {
                printf("%d %d %d", arr[i], arr[j], arr[k]);
                free(arr);
                return 0;
            }

            
            if(current_sum < 0){
                j++;
            } 
            else if(current_sum > 0){
                k--;
            }
            
        }
    }
    
    printf("%d %d %d", arr[idx1], arr[idx2], arr[idx3]);
    
    free(arr);
    return 0;
}