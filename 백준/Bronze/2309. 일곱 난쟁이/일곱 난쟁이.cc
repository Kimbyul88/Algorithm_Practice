#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 7 8 10 13 15 19 20 23 25 = 140
    
    vector<int> a(9);
    for(int i=0;i<9;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int overflow = accumulate(a.begin(), a.end(), 0) - 100; 
    
    for(int i=0;i<9;i++){
        int ifEnd = 0;
        for(int j=i;j<9;j++){
            if(a[i] + a[j] == overflow){
                a[i] = 0;
                a[j] = 0;
                ifEnd = 1;
                break;
            }
        }
        if(ifEnd) break;
    }
    
    for(int i=0;i<9;i++){
        if(a[i]) cout << a[i] << "\n";
    }
    
    return 0;
}