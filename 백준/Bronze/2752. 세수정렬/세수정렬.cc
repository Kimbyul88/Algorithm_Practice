#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> a(3);
    
    for(int i=0;i<3;i++){
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    cout << a[0] << " " << a[1] << " " << a[2];
    
    return 0;
}