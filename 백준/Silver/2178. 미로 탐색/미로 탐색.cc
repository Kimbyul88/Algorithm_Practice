#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[102][102];
int dist[102][102];

int n,m;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> board[i][j];
        }
    }
    
    queue<pair<int,int>> Q;
    
    //일단 시작
    Q.push({1,1});
    dist[1][1] = 1;
    
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<1||ny<1||nx>n||ny>m) continue;
            if(board[nx][ny]=='0'||dist[nx][ny]>0) continue;
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    
    cout << dist[n][m];
    return 0;
}