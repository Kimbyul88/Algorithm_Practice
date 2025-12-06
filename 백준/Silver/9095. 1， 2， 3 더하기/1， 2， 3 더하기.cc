#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp(int n){
    //1 = 1
    //2 = 1+1, 2
    //3 = 1+1+1, 2+1, 1+2, 3
    vector<int> arr(n+1);
    
    //base step
    arr[1] = 1;
    
    for(int i=2;i<=n;i++){
        if(i == 2){
            arr[2] = 2;
            continue;
        }
        if(i == 3){
            arr[3] = 4;
            continue;
        }
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    
    return arr[n];
}

int main(void){
    int count;
    scanf("%d", &count);
    
    vector<int> arr(count);
    
    for(int i=0;i<count;i++){
        scanf("%d", &arr[i]);
        printf("%d\n", dp(arr[i]));
    }
    return 0;
}