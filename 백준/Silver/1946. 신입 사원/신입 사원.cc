#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;;

int main(){
    int t;
    cin >> t;
    
    while(t--){
       int n;
       cin >> n;
    /*
    1 4
    2 5
    3 6
    4 2
    5 7
    6 1
    7 3 
    */
       vector<pair<int,int>> a(n);
       for (int i=0;i<n;i++){
            cin >> a[i].first >> a[i].second;
        }
    
        sort(a.begin(), a.end());
        
        int res = 1;
        int min = a[0].second;
        for(int i=1;i<n;i++){
            if (a[i].second < min){
                min = a[i].second;
                res ++;
            }
        }
        cout << res << '\n';
    }
    
 
    return 0;
}