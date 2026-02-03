#include <bits/stdc++.h>
using namespace std;

// n의 범위가 14이하. 작기 때문에 백트래킹으로 해결해 보자.

int n;
//int arr[16][16];
bool issued1[16];
bool issued2[31];
bool issued3[31];

int cnt = 0;

//row번째 row가 채워졌느냐를 말하는 것.
void func(int row){
    if(row==n){
        cnt++;
        return;
    }
    
    for(int col=0;col<n;col++){
        if(!issued1[col]&&!issued2[row+col]&&!issued3[row-col+n-1]){
            issued1[col] = 1;
            issued2[row+col] = 1;
            issued3[row-col+n-1] = 1;
            func(row+1);
            issued1[col] = 0;
            issued2[row+col] = 0;
            issued3[row-col+n-1] = 0;
        }
    }
    
    
    return;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    func(0);
    
    cout << cnt;
    
    return 0;
}