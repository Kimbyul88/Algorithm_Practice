#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n, 0);
   
    for(int i=0;i<n;i++) cin >> arr[i];
    
    int count = 0;
    int st = 0, en = 0;
    int sum = 0;
    
    while(true){
        if(sum >= m){
            if(sum==m) count++;
            sum -= arr[st++];
        } else {
            if(en==n) break;
            sum += arr[en++];
        }
    }
    
    cout << count;
    
    return 0;
}