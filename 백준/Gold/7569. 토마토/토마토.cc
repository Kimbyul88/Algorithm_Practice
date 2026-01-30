#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define Z third

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int m, n, h;

struct Node {
    int Z, Y, X;
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n >> h;
    
    vector<vector<vector<int>>> board(h, vector<vector<int>>(n, vector<int>(m,0)));
    vector<vector<vector<int>>> dis(h, vector<vector<int>>(n, vector<int>(m,0)));
    
    //토마토 카운트
    int tc = 0;
    
    queue<Node> Q;
    
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                int input;
                cin >> input;
                board[i][j][k] = input;
                if(input==0) tc++;
                if(input==1) Q.push({i,j,k});
            }
        }
    }
    
    //이미 다 익어있을 시
    if(tc==0){
        cout << 0;
        return 0;
    }
    
    int md = 0;
   
    while(!Q.empty()){
        auto cur = Q.front();Q.pop();
        
        for(int dir=0;dir<6;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            int nz = cur.Z + dz[dir];
            if(nx<0||ny<0||nz<0||nx>m-1||ny>n-1||nz>h-1) continue;
            if(board[nz][ny][nx]!=0) continue;
            Q.push({nz, ny, nx});
            board[nz][ny][nx] = 1;
            tc--;
            dis[nz][ny][nx] = dis[cur.Z][cur.Y][cur.X] + 1;
            
            md = max(md, dis[nz][ny][nx]);
        }
        
    }
    
    if(tc>0) cout << -1;
    else cout << md;
   
    return 0;
}