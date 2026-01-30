#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    //원형 링크드 리스트
    list<int> ll = {};
    
    for(int i=0;i<n;i++) ll.push_back(i+1);
    
    list<int>::iterator t = ll.begin();
    
    cout << "<";
    for(int i=0;i<n;i++){
        for(int p=0;p<k-1;p++){
            //nt는 현재 t의 다음 노드를 가리킨다.
            auto nt = next(t);
            //만약 다음 노드가 end()라면 다음노드를 시작노드로 바꾼다.
            // [A] -> [B] -> [C] -> end() 이렇게 돼있는 것!
            if(nt==ll.end()) nt = ll.begin();
            //다음 노드로 t 이동.
            t = nt;
        }
        cout << *t << (i == n-1 ? "" : ", ");
        t = ll.erase(t);
        if(t==ll.end()) t = ll.begin();
        
    }
    cout << ">";
    
    return 0;
}

// 1 2 3 4 5 6 7