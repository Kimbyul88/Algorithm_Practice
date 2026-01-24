#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string String;
    list<char> LL;
    int n;
    
    cin >> String >> n;
    cin.ignore();
    
    //연결리스트 만들기
    for(char c:String){
        LL.push_back(c);
    }
    
    vector<string> arr(n);
    
    for(int i=0;i<n;i++){ 
        getline(cin, arr[i]);
    }
    
    auto curcur = LL.end();//커서의 왼쪽에 있는 것이 현재 선택.
    for(int i=0;i<n;i++){
        if(arr[i] == "L") {
            if(curcur != LL.begin()) curcur--;
        }
        else if(arr[i] == "D"){
            if(curcur != LL.end()) curcur++;
        }
        else if(arr[i] == "B"){
            if(curcur != LL.begin()){
                auto toErase = prev(curcur);
                LL.erase(toErase);
            }
            
        } 
        else{
            char item = arr[i][2];
            LL.insert(curcur,item);
        }
    }
    
    for(auto i : LL) cout << i;
    return 0;
}