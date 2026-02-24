#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct Node{
    int x,y,step;
};

bool isQlistEmpty(vector<deque<Node>>& ql){
    //끝나는 조건 = 큐리스트의 모든 큐가 비었을때..
    // = 큐리스트의 큐의 사이즈의 합이 0일때..
    // OR 그냥 쭉 empty인지 확인하고 아니면 반환
    
    for(deque<Node> q:ql){
        if(!q.empty()){
            return false;
        }
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, p;
    
    cin >> n >> m >> p;
    
    vector<int> s(p+1,0);
    for(int i=1;i<=p;i++) cin >> s[i];
    
    //p+1만큼 큐리스트를 만든다. 
    vector<deque<Node>> qlist(p+1);
    vector<vector<char>> board(n, vector<char>(m,0));
    vector<int> pcount(p+1, 0);
  
    // . = 빈칸 , # = 벽
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        char in;
            cin >> in;
            //p인덱스의 큐에 시작점들을 넣음
            if(in!='#' && in!='.'){
                 qlist[in-'0'].push_back({i,j,0});
                 pcount[in-'0']++;
            }
            board[i][j] = in;
        }
    }

    while(true) {
    bool allEmpty = true;

    for(int np = 1; np <= p; np++) {

        if(qlist[np].empty()) continue;
        allEmpty = false;

        for(int move = 0; move < s[np]; move++) {

            int qsize = qlist[np].size();
            if(qsize == 0) break;

            while(qsize--) {
                Node cur = qlist[np].front();
                qlist[np].pop_front();

                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];

                    if(nx<0||ny<0||nx>=n||ny>=m) continue;
                    if(board[nx][ny] != '.') continue;

                    board[nx][ny] = np + '0';
                    qlist[np].push_back({nx, ny, 0});
                    pcount[np]++;
                }
            }
        }
    }

    if(allEmpty) break;
}

  
    for(int i=1;i<=p;i++) cout << pcount[i] << " ";
    
    return 0;
}