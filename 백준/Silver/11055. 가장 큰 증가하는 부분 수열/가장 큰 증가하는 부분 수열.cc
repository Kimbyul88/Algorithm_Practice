#include <bits/stdc++.h>
using namespace std;

//4, 1, 55, 2, 30, 60
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> num(n+1);
    
    for(int i=1;i<=n;i++) cin >> num[i];
    
    //dp 배열은 n으로 끝나는 수열 중 최대를 저장
    vector<int> dp(n+1, 0); 
    
    //base case
    dp[1] = num[1];
    
    for(int i=2;i<=n;i++){
        dp[i] = num[i];
        for(int j=1;j<i;j++){
            if(num[j]<num[i]) dp[i] = max(dp[i], dp[j]+num[i]);
        }
    }
    
    cout << *max_element(dp.begin(), dp.end());
    
    return 0;
}