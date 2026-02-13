#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin >> arr[i];
    
    vector<int> dp(n+1, 0);
    
    dp[1] = arr[1];
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + arr[i];
    }
    
    while(m--){
        int start, end;
        cin >> start >> end;
        cout << dp[end] - dp[start-1] << "\n";
    }
    
    return 0;
}