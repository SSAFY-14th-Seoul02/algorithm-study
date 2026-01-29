#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int N, M;
vector<vector<int>> graph;  // graph[a] : a를 풀고 나면 풀 수 있는 문제들
vector<int> need;           // need[i] : 문제 i를 풀기 전에 필요한 선행 문제 개수

void topo() {
    // 항상 번호가 가장 작은 문제부터 꺼내기 위한 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; i++) {
        if (need[i] == 0) pq.push(i);
    }

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        cout << cur << ' ';  // 현재 풀 수 있는 문제 출력

        // 현재 문제를 풀었으므로, 이어지는 문제들의 선행 조건 감소
        for (auto nxt : graph[cur]) {
            need[nxt]--;
            if (need[nxt] == 0) {
                pq.push(nxt);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    graph.assign(N + 1, {});
    need.assign(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);  // a를 먼저 풀어야 b를 풀 수 있음
        need[b]++;              // b의 선행 조건 증가
    }

    topo();

    cout << '\n';

    return 0;
}
