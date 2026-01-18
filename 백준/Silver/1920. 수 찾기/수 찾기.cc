#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> nArr(n);
    
    for(int i=0;i<n;i++){
        cin >> nArr[i];
    }
    
    int m;
    cin >> m;
     
    vector<int> mArr(m);
    
    for(int i=0;i<m;i++){
        cin >> mArr[i];
    }
    //n 배열 sort
    sort(nArr.begin(), nArr.end());
    //1 2 3 4 5
    
    for(int i=0;i<m;i++){
       int start = 0;
       int end = n-1;
       bool found = false;
        
       while(start<=end){
            int middle = (start + end) / 2;
           
           if(mArr[i]<nArr[middle]){
               end = middle-1;
           }
           else if(mArr[i]>nArr[middle]){
               start = middle+1;
           }
           else{
              found = true;
               break;
           }
           
       }
        cout << (found ? 1 : 0) << "\n";
    }
    
    
    return 0;
}