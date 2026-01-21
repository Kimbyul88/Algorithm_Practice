#include <iostream>
#include <algorithm>
using namespace std;;

int main(void){
      
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    
    for(int i=0;i<n;i++) {
        int input;
        cin >> input;
        if(input < x) cout << input << " ";
    }
    
    return 0;
}