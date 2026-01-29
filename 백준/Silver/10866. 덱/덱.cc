#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    deque<int> DQ;
    
    while(n--){
        string S;
        cin >> S;
        
        if(S == "push_front"){
            int x;
            cin >> x;
            DQ.push_front(x);
        }
        else if(S == "push_back"){
            int x;
            cin >> x;
            DQ.push_back(x);
        }
        else if(S == "pop_front"){
            if(DQ.empty()) cout << -1 << "\n";
            else { cout << DQ.front() << "\n"; DQ.pop_front(); }
        }
        else if(S == "pop_back"){
            if(DQ.empty()) cout << -1 << "\n";
            else { cout << DQ.back() << "\n"; DQ.pop_back(); }
        }
        else if(S == "size"){
            cout << (int)DQ.size() << "\n";
        } 
        else if(S == "empty"){
            cout << (DQ.empty() ? 1 : 0) << "\n";
        }
        else if(S == "front"){
            cout << (DQ.empty() ? -1 : DQ.front()) << "\n";
        }
        else if(S == "back"){
            cout << (DQ.empty() ? -1 : DQ.back()) << "\n";
        }
    }
    
    return 0;
}