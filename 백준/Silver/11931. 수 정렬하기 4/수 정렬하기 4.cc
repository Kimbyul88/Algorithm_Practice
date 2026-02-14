#include <bits/stdc++.h>
using namespace std;

bool compare(int i, int j){
    return i > j;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end(), compare);
    
    for(int i=0;i<n;i++) cout << arr[i] << "\n";
    
    return 0;
}