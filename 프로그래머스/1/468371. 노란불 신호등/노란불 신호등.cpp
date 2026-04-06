#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> signals) {
    //그냥 그리디로 풀어보자. 
    
    int t = signals.size();

    //cgb = 최대 배수
    int cgb = 1;
    for(int i=0;i<t;i++){
        int acc = 0;
        for(int j = 0; j<signals[i].size();j++){
            acc += signals[i][j];
        }
        cgb *= acc;
    }
    
    vector<vector<int>> board(t, vector<int>(cgb,0));
    
    while(t--){
        for(int i=0;i<cgb/(signals[t][0]+signals[t][1]+signals[t][2]);i++){
            for(int y=1;y<=signals[t][1];y++){
                //방정식
                int func = y + signals[t][0] + (signals[t][0]+ signals[t][2] + signals[t][1])*i;
                board[t][func] = 1;
            }
        }
    }
    
    int answer = 0;
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<cgb;j++){
            // cout << board[i][j] << " ";
        }
        // cout << "\n";
    }
    // cout << "\n";
    
    for(int i=1;i<cgb;i++){
        int sum = 0;
        for(int ti=0;ti<board.size();ti++){
            sum += board[ti][i];
             
        }
        if(sum==board.size()){
            answer = i;
            return answer;
        }
    }
    
    return -1;
}