#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;;

int main(){
    int t;
    cin >> t;
    
    static int Arr[100001];
    
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
       for (int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            Arr[a] = b;
        }
    
        //sort(a.begin(), a.end());
        
        int res = 1;
        int min = Arr[1];
        for(int i=2;i<=n;i++){
            if (Arr[i] < min){
                min = Arr[i];
                res ++;
            }
        }
        cout << res << '\n';
    }
    
 
    return 0;
}