#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
using namespace std;

//같은수 여러번 가능
//오름차순이어야 한다

//조합 문제!!

int n, m;

int arr[10];
int input[10];

bool issued[10];

// vector<int> input(10, 0);

void func(int k){
    //m개를 만족하면 종료하고 프린트
    if(k==m+1){
        for(int i=1;i<=m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    //루프를 통해 재귀.
    for(int st=1;st<=n;st++){
        if(!issued[st]){
            arr[k] = input[st];
            issued[st] = 1;
            func(k+1);
            issued[st] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> input[i];
    }
    
    sort(input+1, input+n+1);
    
    //cout << "\n" << "input: ";
    //for(int i : input) cout << i << " ";
    //cout << "\n";
    
    func(1);
    
    return 0;
}