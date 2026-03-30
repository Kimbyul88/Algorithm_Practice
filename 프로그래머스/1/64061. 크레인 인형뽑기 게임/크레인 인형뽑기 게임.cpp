#include <bits/stdc++.h>

using namespace std;

int moves[1000];

//터트려져 사라진 인형의 개수 리턴
int solution(vector<vector<int>> board, vector<int> moves) {
    deque<int> Q;
    int answer = 0;
    for(int i=0; i<moves.size(); i++) {
        int get = 0;
        int idx = 0;
        while(idx < board.size()){
            get = board[idx][moves[i]-1];
            if(get==0) idx++;
            else{
                board[idx][moves[i]-1] = 0;
                break;
            }
        }
        
         if(get == 0) continue; 
        
        if(!Q.empty() && Q.back() == get){
    Q.pop_back();
    answer += 2;
}
        else{
            Q.push_back(get);
        }
    }
    return answer;
}