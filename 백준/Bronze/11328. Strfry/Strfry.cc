#include <bits/stdc++.h>
using namespace std;

int n, target;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
   int n;
   cin >> n;
   
   for(int i=0;i<n;i++){
       vector<int> a(26,0);
       vector<int> b(26,0);
       
       string first, second;
       cin >> first >> second;
       
        for(char c: first) a[c-'a']++;
        for(char c: second) b[c-'a']++;
        
        bool possible = 1;
        for(char c: second){
            if(a[c-'a']!=b[c-'a']){
                possible = 0;
                break;
            }
        }
           
        possible ? cout << "Possible" : cout << "Impossible";
        cout << "\n";
   }
    
    return 0;
}