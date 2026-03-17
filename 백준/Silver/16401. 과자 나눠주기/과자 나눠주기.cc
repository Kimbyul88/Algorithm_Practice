#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//m = 조카 수, n = 과자 수
bool solve(int m, int n, int x, vector<int> &L){
    if(x==0) return true;
    
    ll cnt = 0;
    for(int i=0;i<n;i++){
        cnt += L[i] / x;
    }
    return cnt >= m;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m,n;
    
    cin >> m >> n;
    
    vector<int> L(n);
    
    for(int i=0;i<n;i++) cin >> L[i];
    
    int st = 0;
    int en = *max_element(L.begin(), L.end());
    
    while(st<en){
        int mid = (st + en + 1) / 2;
        if(solve(m,n,mid,L)){
            st = mid;
        }
        else en = mid -1 ;
    }
    
    cout << st << "\n";
    
    return 0;
    
}