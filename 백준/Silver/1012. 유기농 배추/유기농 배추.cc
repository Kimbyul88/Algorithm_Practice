#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, m, k;
    cin >> t;
  
    while(t--){
         cin >> m >> n >> k;
 
        vector<vector<int>> board(n,vector<int>(m,0));
        vector<vector<int>> visit(n,vector<int>(m,0));
        //보드 채우기
        for(int i=0;i<k;i++){
            int tx, ty;
            cin >> tx >> ty;
            board[ty][tx] = 1;
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visit[i][j]||!board[i][j]) continue;
                count ++;
                //큐
                queue<pair<int, int>> Q;
                //시작
                Q.push({i, j});
                visit[i][j] = 1;
                
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    int y = cur.first;
                    int x = cur.second;
                
                    for(int dir=0; dir<4; dir++){
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];
                
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(visit[ny][nx] || !board[ny][nx]) continue;
                
                        visit[ny][nx] = 1;
                        Q.push({ny, nx});
                    }
                }
            }
        }
        
        cout << count << "\n";
    }
   
    return 0;
}