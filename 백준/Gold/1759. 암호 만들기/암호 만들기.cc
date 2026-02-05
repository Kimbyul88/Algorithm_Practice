#include <bits/stdc++.h>
using namespace std;

//한개의 모음, 두개의 자음
//알파벳 오름차순 
// 중복 없다. -> 조합
int l, c;

char input[17];
char arr[17];
int vowel[5] = {'a'-'a', 'e'-'a', 'i'-'a', 'o'-'a', 'u'-'a'};
int alpha[26];

void func(int k, int start){
    if(k==l){
        int vc = 0;
        for(int i=0;i<k;i++){
             int idx = arr[i] - 'a';
             vc += alpha[idx];
        }
        if(vc < 1 || l-vc < 2) return;
        
        for(int i=0;i<k;i++){
             cout << arr[i];
        }
        cout << "\n";
        return;
    }
    
    for(int st=start;st<c;st++){
        arr[k] = input[st];
        func(k+1, st+1);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //알파벳 배열 초기화
    fill(alpha, alpha+26, 0);
    for(int i=0;i<5;i++){
        alpha[vowel[i]]++;
    }
    
    cin >> l >> c;
    
    for(int i=0;i<c;i++){
        char in; int ton;
        cin >> in;
        input[i] = in;
    }
    
    sort(input, input + c);
    
    func(0,0);
    
    return 0;
}