#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //dp[n] = dp[n-2] + 1 + dp[n-1]
    
    int n;
    cin >> n;
    
    vector<long long> dp(n+1,0);
    
    //base case
    dp[1] = 1; dp[2] = 3;
    
    //dp loop
    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2]*2) % 10007;
    }
    
    cout << dp[n] ;
    
    return 0;
}