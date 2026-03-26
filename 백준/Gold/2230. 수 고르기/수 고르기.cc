#include <bits/stdc++.h>
using namespace std;

int n,m;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin >> arr[i];
    
    int st = 0, en = 0;
    
    int min_v = INT_MAX;
    
    sort(arr.begin(), arr.end());
    
    for(int i=0;i<n;i++){
        st = i;
        
        while(en!=n){
            if(arr[en]-arr[st]>=m){
                min_v = min(min_v, arr[en]-arr[st]);
                break;
            }else{
                en++;
            }
        }
    }
    
    cout << min_v;
    
    return 0;
}