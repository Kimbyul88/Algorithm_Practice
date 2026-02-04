#include <bits/stdc++.h>
using namespace std;

//같은수 여러번 가능
//오름차순이어야 한다

int n, m;

int arr[10];

void func(int k, int start){
    //m개를 만족하면 종료하고 프린트
    if(k==m+1){
        for(int i=1;i<=m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    //루프를 통해 재귀.
    for(int st=start;st<=n;st++){
        arr[k] = st;
        func(k+1, st);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    func(1,1);
    //cout << "\n" << "arr: ";
    //for(int i : arr) cout << i << " ";
    return 0;
}