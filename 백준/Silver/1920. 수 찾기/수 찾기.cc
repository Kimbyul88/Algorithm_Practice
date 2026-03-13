#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n;
    
    vector<int> A(n);
    for(int i=0;i<n;i++){
         cin >> A[i];
    }
    cin >> m;
    vector<int> B(m);
    for(int i=0;i<m;i++) cin >> B[i];
    
    //일단 A 소트
    sort(A.begin(), A.end());
    //1 2 3 4 5
    
    for(int i=0;i<m;i++){
        int start = 0;
        int end = n-1;
        bool flag = false;
        while(start<=end){
           int mid = (start + end) / 2;
            //가운데 숫자와 크기비교
            if(A[mid]>B[i]){
                end = mid-1;
            }
            else if(A[mid] < B[i]){
                start = mid+1;
            }
            else{
               flag = true;
               break;
            }
        }
        if(flag) cout << 1;
        else cout << 0;
        cout << "\n";
    }
    
    return 0;
}