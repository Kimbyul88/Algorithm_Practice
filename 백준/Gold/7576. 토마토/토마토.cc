#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> m >> n;
    
    vector<vector<int>> board(n,vector<int>(m,0));
    // vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> dis(n,vector<int>(m,0));
    //tomato count
    int tc = 0;
    
    queue<pair<int,int>> Q;
    
    //보드 채우기
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int input;
            cin >> input;
            board[i][j] = input;
            //-1이 아니라면 토마토 카운트를 한다. 
            if(input==0) tc++;
            if(input==1){
                Q.push({i,j});
                //vis[i][j] = 1;    
            }
        }
    }
    
    if(tc==0){
        cout << 0;
        return 0;
    }
    //cout << "tc:" << tc << "\n";
    
    //시작
    //Q.push({i,j});
    //vis[i][j] = 1;
    
    pair<int,int> cur;
    
    while(!Q.empty()){
        cur = Q.front(); Q.pop();
        //cout << "left tc:" << tc << "\n";
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||ny<0||nx>n-1||ny>m-1) continue;
            if(board[nx][ny]!=0) continue;
            Q.push({nx, ny});
            board[nx][ny] = 1;
            tc--;
            if (dis[nx][ny]){
                dis[nx][ny] = min(dis[cur.X][cur.Y] + 1, dis[nx][ny]);
            }
            else dis[nx][ny] = dis[cur.X][cur.Y] + 1;
        }
    }
            
           
    
    //max day
    int md = 0;
    for (auto& row : dis) {
        md = max(md, *max_element(row.begin(), row.end()));
    }
    
    if(tc>0){
        cout << -1;
        return 0;
    } else{
        cout << md;
        return 0;
    }
}