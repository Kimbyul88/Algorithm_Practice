#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    
    for(int i=m;i<=n;i++){
        bool flag = true;
        for(int j=2;j<=floor(sqrt(i));j++){
            if(i%j==0){
                flag = false;
                break;
            }
        }
        if(flag&&i!=1) cout << i << "\n";
    }
    
    return 0;
}

