#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<long long>> dp(n+1, vector<long long>(2,0));
    
    //dp[n][0] = 끝이 0인거 개수
    //dp[n][1] = 끝이 1인거 개수
    
    //base case
    dp[1][1] = 1; 
    
    for(int i=2;i<=n;i++){
        //dp[i] = (dp[i-1] 에서 끝이 0인거 * 2) + (dp[i-1] 에서 끝이 1인거)
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    
    cout << dp[n][0] + dp[n][1];
    
    return 0;
}