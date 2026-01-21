#include <bits/stdc++.h>

using namespace std;

string resString = "DCBAE";

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int input;
    
    for(int i=0;i<3;i++){
        int result = 0;
        for(int j=0;j<4;j++){
            cin >> input;
            if (input) result++;
        }
        cout << resString[result] << "\n";
    }
    
    return 0;
}