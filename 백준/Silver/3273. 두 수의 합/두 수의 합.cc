#include <bits/stdc++.h>
using namespace std;



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, target;
    cin >> n;
    
    vector<int> a(n);
    
    for(int i=0;i<n;i++) cin >> a[i];
    cin >> target;
    
    sort(a.begin(), a.end());
    
    // 1 2 3 5 7 9 10 11 13
    
    int l = 0;
    int r = n-1;
    
    int res = 0;
    
    while(l<r){
        int checker = a[l] + a[r];
        if(checker == target){
            res++;
            l++;
            r--;
        }
        else if(checker < target) l++;
        else r--;
    }
    
    cout << res;
    
    return 0;
}