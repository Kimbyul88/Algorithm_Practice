#include<iostream>
#include<vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    //dp 배열은 1차원 될듯? 한 칸당 최소 사용 가능 개수, 불가능하면 무한대
    vector<int> dp(k+1, INT_MAX/2);
    dp[0] = 0;
    
    for(int c:arr){
        for(int sum=c;sum<=k;sum++){
            dp[sum] = min(dp[sum], dp[sum-c]+1);
        }
    }
    
    cout << (dp[k] >= INT_MAX/2 ? -1 : dp[k]);
    return 0;
}