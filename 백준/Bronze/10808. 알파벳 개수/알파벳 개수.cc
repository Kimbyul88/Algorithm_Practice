#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string S;
    cin >> S;
    
    int a = 'a';
    int z = 'z';
    
    vector<int> arr(z-a+1, 0);
    
    
    for(char c : S){
        arr[c-'a'] ++;
    }
    
    for(int i=0;i<z-a+1;i++){
        cout << arr[i] << " ";
    }
    
    return 0;
} 