#include <bits/stdc++.h>

using namespace std;

vector<int> parent;

// 부모 찾기
int findParent(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

// 합치기
void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    parent.resize(n);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // 일단 비용을 기준으로 정렬
    sort(costs.begin(), costs.end(),
         [](vector<int> a, vector<int> b) {
             return a[2] < b[2];
         });

    // 가장 싼 다리부터 확인
    for (auto cost : costs) {
        int a = cost[0];
        int b = cost[1];
        int c = cost[2];

        // 서로 연결 안 되어 있으면
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            answer += c;
        }
    }

    return answer;
}