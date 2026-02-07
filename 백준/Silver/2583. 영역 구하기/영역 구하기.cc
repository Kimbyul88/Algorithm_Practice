#include <bits/stdc++.h>
using namespace std;

int m, n, k;

struct Node {
    int x, y;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void getXY(vector<vector<int>> &board){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i=y1;i<y2;i++){
        for(int j=x1;j<x2;j++){
            board[i][j] = 0;
        }
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n >> k;
    
    vector<vector<int>> board(m, vector<int>(n, 1));
     
    for(int i=0;i<k;i++){
       getXY(board);
    }
    
    int cnt = 0;
    vector<int> V;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            //board가 1이어야지만 루프 가능
            if(!board[i][j]) continue;
                        
            queue<Node> Q;
            cnt++;
    
            //시작
            Q.push({i, j});
            board[i][j] = 0;
            
            int sc = 1;
            
            while(!Q.empty()){
                Node cur = Q.front(); Q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if(nx<0||ny<0||nx>=m||ny>=n) continue;
                    if(!board[nx][ny]) continue;
                    Q.push({nx, ny});
                    sc++;
                    board[nx][ny] = 0;
                }
            }
            
            V.push_back(sc);
        }
    }
    
    cout << cnt << "\n";
    sort(V.begin(), V.end());
    
    for(int i : V){
        cout << i << " ";
    }
    
    return 0;
}