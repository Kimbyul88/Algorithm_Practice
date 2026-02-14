#include <bits/stdc++.h>
using namespace std;

struct P{
    int age;
    string name;
};

bool cmp(const P& a, const P& b){
    return a.age < b.age;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<P> arr(n);
    
    for(int i=0;i<n;i++){
        cin >> arr[i].age >> arr[i].name;
    }
    
    stable_sort(arr.begin(), arr.end(), cmp);
    
    for(int i=0;i<n;i++){
        cout << arr[i].age << " " << arr[i].name << "\n";
    }
    
    return 0;
}