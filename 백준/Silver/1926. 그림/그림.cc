#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502];
bool vis[502][502];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs(int start, int end, int n, int m){
    if(vis[start][end]||board[start][end]==0) return 0;
    
     //큐 만들기
    queue<pair<int,int>> Q;
    
    //시작
    vis[start][end] = 1;
    Q.push({start,end});
    
    int width = 0;
    
    //큐가 비면 끝난다. 
    while(!Q.empty()){
        //큐에서 일단 팝을 한다. 
        width++;
        pair<int,int> cur = Q.front(); Q.pop();
        
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            //큐에 안 담는 조건
            if(nx<0||ny<0||nx>n-1||ny>m-1) continue;
            if(vis[nx][ny]||!board[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    
    //넓이를 반환.
    return width;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //입력    
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    
    int count = 0;
    int max_width = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int res = bfs(i, j, n, m);
           
            if(res){
                max_width = max(res, max_width);
                count++;  
            }
        }
    }
    
    cout << count << "\n" << max_width;
    return 0;
}