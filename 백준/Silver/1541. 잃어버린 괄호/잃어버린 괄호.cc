#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    string temp;
    bool minus = false;

    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == '+' || s[i] == '-') {
            int num = stoi(temp);
            if (minus) ans -= num;
            else ans += num;
            temp.clear();

            if (i < s.size() && s[i] == '-') {
                minus = true; 
            }
        } else {
            temp += s[i];
        }
    }

    cout << ans;
}
