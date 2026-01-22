#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> a(10,0);
    
    while(N){
        a[N%10]++;
        N /= 10;
    }
    
    int n69 = (a[6] + a[9]+1)/2;
    a[6] = n69;
    a[9] = n69;
    
    cout << *max_element(a.begin(), a.end());
    return 0;
}