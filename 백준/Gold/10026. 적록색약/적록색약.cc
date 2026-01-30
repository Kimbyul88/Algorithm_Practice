#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<char>> board(n, vector<char>(n));
    vector<vector<char>> board2(n, vector<char>(n));
    vector<vector<int>> visit(n, vector<int>(n, 0));
    
    //보드 채우기
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin >> c;
            board[i][j] = c;
            if(c=='G') board2[i][j] = 'R';
            else board2[i][j] = c;
        }
    }
    //적록색약 있음
    int yCount = 0;
    //적록색약 없음
    int nCount = 0;
    queue<pair<int,int>> Q;
    
    //현재 컬러
    int color;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //시작점을 찾는다. 방문한 적 있으면 패쓰
            if(visit[i][j]) continue;
            
            //시작
            Q.push({i,j});
            visit[i][j] = 1;
            //컬러 카운트 추가
            nCount++;
            
            color = board[i][j];
            while(!Q.empty()){
                pair<int,int> cur = Q.front();Q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    //인덱스 범위 벗어남
                    if(nx<0||ny<0||nx>n-1||ny>n-1) continue;
                    //문제 조건에서 벗어남
                    if(!board[nx][ny]||visit[nx][ny]||board[nx][ny]!=color) continue;
                    Q.push({nx, ny});
                    visit[nx][ny] = 1;
                }
            }
        }
    }
    
    visit.assign(n, vector<int>(n, 0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //시작점을 찾는다. 방문한 적 있으면 패쓰
            if(visit[i][j]) continue;
            
            //시작
            Q.push({i,j});
            visit[i][j] = 1;
            //컬러 카운트 추가
            yCount++;
            
            color = board2[i][j];
            while(!Q.empty()){
                pair<int,int> cur = Q.front();Q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    //인덱스 범위 벗어남
                    if(nx<0||ny<0||nx>n-1||ny>n-1) continue;
                    //문제 조건에서 벗어남
                    if(!board2[nx][ny]||visit[nx][ny]||board2[nx][ny]!=color) continue;
                    Q.push({nx, ny});
                    visit[nx][ny] = 1;
                }
            }
        }
    }
    
    cout << nCount << " " << yCount;
    return 0;
}