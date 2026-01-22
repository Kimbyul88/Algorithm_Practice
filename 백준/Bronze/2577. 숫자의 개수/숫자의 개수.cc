#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n1, n2, n3;
    
    cin >> n1 >> n2 >> n3;
    
    int mul = n1 * n2 * n3;
    
    vector<int> arr(10, 0);
    
    int i=1;
    while(mul){
        arr[mul % 10]++;
        mul /= 10;
        i++;
    }
    
    for(int a : arr) cout << a << "\n";
    
    return 0;
}