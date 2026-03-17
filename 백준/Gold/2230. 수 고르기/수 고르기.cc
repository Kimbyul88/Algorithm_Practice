#include <bits/stdc++.h>
using namespace std;

int n,m;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin >> A[i];
    
    sort(A.begin(),A.end());
    int start = 0;
    int end = A.size() - 1;
    
    deque<int> Q;
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int minus = A[j] - A[i];
            if(minus>=m){
                Q.push_back(minus);
                break;
            }
        }
    }
    
    cout << *min_element(Q.begin(), Q.end());
    // 1 3 4 6 7 , m = 3
    
    return 0;
    
}