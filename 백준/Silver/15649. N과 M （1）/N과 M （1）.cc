#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10]; //완성된 수열을 담을 배열
bool issued[10]; // 배열 불리언을 통해 해당 인덱스가 채워졌는지 확인.
/*
백 트래킹 수행. m의 인덱스를 채워야한다. 
*/
void func(int k){
    //k는 이제 채워야되는 인덱스.

    if(k==m){
        for(int i=0;i<m;i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=1;i<=n;i++){
        if(!issued[i]){
            arr[k] = i;
            issued[i] = 1;
            func(k+1);
            issued[i] = 0;
        }
    }    
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    //수열을 모~두 구한다. 백트래킹.
    func(0);
    
    return 0;
}