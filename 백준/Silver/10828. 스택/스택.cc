#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    stack<int> st;
    
    cin >> n;
    cin.ignore();
    
    while(n--){
        string line;
        cin >> line;
        if(line == "push"){
            int x;
            cin >> x;
            st.push(x);
        }
        else if(line == "pop"){
            if(st.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if(line =="size"){
            cout << st.size() << "\n";
        }
        else if(line =="empty"){
            if(st.empty()){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(line =="top"){
            if(st.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << st.top() << "\n";
            }
        }
    }
    
    return 0;
}