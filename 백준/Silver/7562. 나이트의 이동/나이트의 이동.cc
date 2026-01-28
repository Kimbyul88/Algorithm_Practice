#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> dis(n, vector<int>(n,0));
        vector<vector<int>> vis(n, vector<int>(n,0));
        
        pair<int,int> pre, fur;
        cin >> pre.X >> pre.Y >> fur.X >> fur.Y;
        
        queue<pair<int,int>> Q;
        
        //시작
        Q.push({pre.X, pre.Y});
        vis[pre.X][pre.Y] = 1;
        
        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            
            //목적지를 찾았을때
            if(cur.X == fur.X && cur.Y == fur.Y) break;
           
            for(int dir=0;dir<8;dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx< 0||ny<0||nx>n-1||ny>n-1) continue;
                if(vis[nx][ny]) continue;
                Q.push({nx,ny});
                vis[nx][ny] = 1;
                dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            }
        }
        
        cout << dis[fur.X][fur.Y] << "\n";
    }
    
    return 0;
}