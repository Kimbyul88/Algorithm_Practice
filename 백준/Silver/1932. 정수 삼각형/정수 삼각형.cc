#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n; // 삼각형 크기
    
    //삼각형 배열
    vector<vector<int>> tri(n);
    
    for(int i=0;i<n;i++){
        tri[i].resize(i+1);
        
        for(int j=0;j<i+1;j++){
            cin >> tri[i][j];
        }
    }
    
    //dp 배열
    vector<int> dp(n+1,0);
    
    dp[0] = tri[0][0];
    
    for(int i=1;i<n;i++){
        for(int j=i;j>=0;j--){
            if(j==0){
                dp[j] += tri[i][j];
            } 
            else if(j==i){
                dp[j] = dp[j-1] + tri[i][j];
            }else{
                dp[j] = max(dp[j],dp[j-1]) + tri[i][j];
            }
        }
    }
    
    cout << *max_element(dp.begin(), dp.begin() + n);
    return 0;
} 