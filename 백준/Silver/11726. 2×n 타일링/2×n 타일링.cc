#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin >> n;
    
    vector<int> dp(n+1);
    
    dp[1] = 1;
    if (n >= 2) {
        dp[2] = 2;
    }
    
    //1 -> 1
    //2 -> 1+1, 2
    //3 -> 1+1+1, 1+2, 2+1
    //4 -> (3개) + (2개) = 5
    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    } 
    
    
    printf("%d", dp[n]);
}