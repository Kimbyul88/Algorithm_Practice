#include <iostream>
#include <vector>
#include <algorithm>
//3
//26 40 83
//49 60 57
//13 89 99

using namespace std;

int main(void){
    int n;
    cin >> n;
    
    std::vector<std::vector<int>> dp(n+1,std::vector<int>(3+1));
    //base step
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<4;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<4;i++){
        cin >> dp[1][i];
    }
    int cost1, cost2, cost3;
    for(int i=2;i<=n;i++){
      cin >> cost1;
      cin >> cost2;
      cin >> cost3;
      dp[i][1] = cost1 + min(dp[i-1][2], dp[i-1][3]);
      dp[i][2] = cost2 + min(dp[i-1][1], dp[i-1][3]);
      dp[i][3] = cost3 + min(dp[i-1][1], dp[i-1][2]);
    }
    
    printf("%d", min(min(dp[n][1], dp[n][2]),dp[n][3]));
    return 0;
}