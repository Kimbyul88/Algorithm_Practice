#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long modPow(long long a, long long b, long long c) {
    if (b == 0) return 1;
    long long half = modPow(a, b / 2, c);
    long long result = (half * half) % c;
    if (b % 2 == 1) result = (result * a) % c;
    return result;
}


int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << modPow(a, b, c);
}
