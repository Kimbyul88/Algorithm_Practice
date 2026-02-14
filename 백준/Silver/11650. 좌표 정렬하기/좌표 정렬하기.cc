#include <bits/stdc++.h>
using namespace std;

struct P{
    int x;
    int y;
};

bool cmp(const P& a, const P& b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<P> arr(n);
    
    for(int i=0;i<n;i++){
        cin >> arr[i].x >> arr[i].y;
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    for(int i=0;i<n;i++){
        cout << arr[i].x << " " << arr[i].y << "\n";
    }
    
    return 0;
}