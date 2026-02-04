#include <bits/stdc++.h>
using namespace std;
#define SELECT 6
int n;
//arr는 골라진 수들 배열.
int arr[50];
//issued는 arr[i]가 선택이 되었느냐를 판단. 
//bool issued[50];

int selected[SELECT];
//k는 인덱스 번호. 
void func(int k, int start){
    if(k==SELECT){
        for(int s:selected){
            cout << s << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=start;i<n;i++){
            selected[k] = arr[i];
            func(k+1, i+1);
        
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        cin >> n;
        if(n==0) break;
        //arr 에 넣기
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        func(0,0);
        cout << "\n";
    }
    
    return 0;
}