#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    stack<int> st;

    while(n--){
        int c;
        cin >> c;
        
        if(c==0&&!st.empty()) st.pop();
        else st.push(c);
    }
    
    int total = 0;
    
    while(!st.empty()){
        total += st.top();
        st.pop();
    }
    cout << total;
    
    
    return 0;
}