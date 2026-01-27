#include <bits/stdc++.h>
using namespace std;

int dx[3] = {-1, 1, 0};
const int MAX = 100000;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //dp -> 
    //bfs -> 쭉 뻗어 간다. 
    int n , k;
    cin >> n >> k;
    
    if(n>=k){
        cout << n-k;
        return 0;
    }
    
    //dist 저장 벡터
    vector<int> dist(MAX+1, -1);
    
    queue<int> Q;
    
    //시작
    Q.push(n);
    dist[n] = 0;
    
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur==k) break;
        for(int dir=0;dir<3;dir++){
             int nx = dx[dir] ? cur+dx[dir] : cur*2;
             if(nx<0||nx>MAX) continue;
             if(dist[nx]>=0) continue;
             Q.push(nx);
             dist[nx] = dist[cur] + 1;
        }
        
    }
    
    cout << dist[k];
    return 0;
}