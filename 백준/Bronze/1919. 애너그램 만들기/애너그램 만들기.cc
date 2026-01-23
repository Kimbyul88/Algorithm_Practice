#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> a(26,0);
    
    string s1, s2;
    cin >> s1 >> s2;
    
    for(char ch:s1) a[ch-'a']--;
    for(char ch:s2) a[ch-'a']++;
    
    int res = 0;
    for(int x:a) res+=abs(x);
    cout << res;
    return 0;
}