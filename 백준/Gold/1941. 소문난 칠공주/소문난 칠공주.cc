#include <bits/stdc++.h>
using namespace std;

/*
1. 일단 25c7을 한다. 
2. 각 경우에서 조건 확인
    1) S가 4개이상인가?
    2) 다 이어져 있는가? (bfs)
*/

#define SEVEN 7

vector<vector<char>> input(5, vector<char>(5));
vector<vector<char>> issued(5, vector<char>(5));
vector<pair<int,int>> arr(7);

vector<vector<int>> visit(5, vector<int>(5,0));

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int cnt = 0;

bool bfs(){
    vector<vector<int>> visit(5, vector<int>(5, 0));
    queue<pair<int,int>> Q;
    
    //시작
    Q.push({arr[0]});
    visit[arr[0].first][arr[0].second] = 1;
    
    int bfscnt = 1;
    
    while(!Q.empty()){
        pair<int,int> cur = Q.front();Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0||ny<0||nx>4||ny>4) continue;
            if(visit[nx][ny]||!issued[nx][ny]) continue;
            Q.push({nx, ny});
            visit[nx][ny] = 1;
             bfscnt++;
        }
    }
    if(bfscnt==7) return true;
    else return false;
}

bool cntds(){
    int scnt = 0;
    for(auto a:arr){
        if(input[a.first][a.second]=='S') scnt++;        
    }
    if(scnt>=4) return true;
    else return false;
}

void func(int k, int start){
    if(k==SEVEN){
        if(cntds()&&bfs()) cnt++;
        return;
    }
    for(int s=start;s<25;s++){
        int i = s / 5;
        int j = s % 5;
         if(!issued[i][j]){
            arr[k] = {i,j};
            issued[i][j] = 1;
            func(k+1,s+1);
            issued[i][j] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> input[i][j];
        }
    }
    
    func(0,0);
    
    cout << cnt;
    
    return 0;
}