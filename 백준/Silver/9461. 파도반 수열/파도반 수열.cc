#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll P[101];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        
        P[1] = 1; P[2] = 1; P[3] = 1; P[4] = 2; P[5] = 2;
        
        for(int i=6;i<=n;i++){
            P[i] = P[i-1] + P[i-5];
        }
        
        cout << P[n] << "\n";
    }
    
    return 0;
}