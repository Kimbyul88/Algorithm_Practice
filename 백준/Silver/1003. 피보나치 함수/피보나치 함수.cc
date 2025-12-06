#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dp(int n){
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(2));
    //basecase
    dp[0][0] = 1;
    dp[0][1] = 0;
   
    
    if (n > 0) {
        dp[1][0] = 0;
        dp[1][1] = 1;
    }
     //
    //n==2 -> f(0) + f(1)
    //n==3 -> f(1) + f(2)
    //n==4 -> f(2) + f(3)
    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-2][0] + dp[i-1][0];
        dp[i][1] = dp[i-2][1] + dp[i-1][1];
    }
    
    printf("%d %d\n", dp[n][0], dp[n][1]);
    return;
}

int main(void){
    int T;
    scanf("%d", &T);
    
    
    for(int i=0;i<T;i++){
        int input;
        scanf("%d", &input);
        dp(input);
    }
    
    return 0;
}