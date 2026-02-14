#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> arr(10001,0);
    
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        arr[in]++;
    }
    
    //sort(arr.begin(), arr.end());
    
    for(int i=1;i<10001;i++){
        if(n==0) break;
        
        if(arr[i]){
            while(arr[i]--) cout << i << "\n";
            n--;
        }
    }
    
    return 0;
}