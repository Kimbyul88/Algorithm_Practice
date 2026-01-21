#include <bits/stdc++.h>

using namespace std;

constexpr int MAN = 10000;
constexpr int CHUN = 1000;
constexpr int BAEK = 100;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    
    if(n1 == n2 && n2 == n3) cout << MAN + n1 * CHUN;
    else if(n1 == n2) cout << CHUN + n1 * BAEK;
    else if(n2 == n3) cout << CHUN + n2 * BAEK;
    else if(n1 == n3) cout << CHUN + n1 * BAEK;
    else cout << max({n1, n2, n3}) * BAEK;
    
    return 0;
}