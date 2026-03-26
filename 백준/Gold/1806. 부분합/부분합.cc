#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,s;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    //합이 S 이상 되는것 중 가장 짧은 것의 길이
    
    vector<ll> arr(n);
    
    for(ll i=0;i<n;i++) cin >> arr[i];
    
    ll st = 0, en = 0;
    
    ll minl = INT_MAX;
    ll sum = arr[0];
    if(sum>=s){
        cout << 1;
        return 0;
    }
    
    while(st!=n){
        if(sum<s){
            if(en==n-1) break;
            //아직 s보다 작으면 en을 늘린다.
            en++;
            sum += arr[en]; 
        }else{
            //s 이상이 되면 min 업뎃, st를 늘린다. 
            minl = min(minl, en-st+1);
            sum -= arr[st];
            st++;
        }
    }
    
    if(minl == INT_MAX) cout << 0;
else cout << minl;
    
    return 0;
}