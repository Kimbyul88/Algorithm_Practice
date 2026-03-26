#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<bool> isPrime(n+1, true);
    isPrime[0] = false; isPrime[1] =false;
    
    //에라토스테네스의 체 : 소수가 아닌 것을 모두 지우는 방식
    for(int i=2;i<=sqrt(n);i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                //현재 i의 배수를 모두 삭제한다. 
                isPrime[j] = false;
            }
        }
    }
    
    //진짜 소수 배열을 만든다. 
    vector<int> prime;
    for(int i=2;i<=n;i++){
        if(isPrime[i]) prime.push_back(i);
    }

    
    int sum = 0;
    int st = 0, en = 0;
    int count = 0;

    while(true){
        if(sum>=n){
            if(sum==n) count++;
            sum -= prime[st++];
        }else{
            if(en == prime.size()) break;
            sum += prime[en++];
        }
    }
    
    cout << count;
    
    return 0;
}