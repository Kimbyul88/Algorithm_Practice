#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int start;
    int end;
}ELEMENT;

int compare(const void *a, const void *b) {
    //end에 따라 정렬
    ELEMENT* el1 = ((ELEMENT*)a);
    ELEMENT* el2 = ((ELEMENT*)b);

    if (el1->end < el2->end) return -1;
    if (el1->end > el2->end) return 1;
    if(el1->end == el2->end){
        if(el1->start<el2->start) return -1;
        if(el1->start>el2->start) return 1;
        return 0;
    }
}



int main(void){
    int n;
    scanf("%d",&n);
    
    ELEMENT* arr = (ELEMENT*)malloc(sizeof(ELEMENT)*n); 
    
    for(int i=0;i<n;i++){
        scanf("%d ", &arr[i].start);
        scanf("%d", &arr[i].end);
    }
    //end 순으로 오름차순 정렬
    qsort(arr,n,sizeof(ELEMENT),compare);
    
    //가장 작은 end를 꺼내고 그보다 큰 start를 가지면서 가장 작은 end를 또 꺼내고..
    int count = 1;
    int current_end = 0;
    for(int i=1;i<n;i++){
        if(arr[i].start<arr[current_end].end){
            continue;
        } else{
            count++;
            current_end = i;
        }
    }
    
    printf("%d", count);
    
}