#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, A, B, C;
vector<vector<pair<int, int>>> graph;

// 최대 간선 비용이 x 일 때, A->B를 C 안에 가능한지
bool dijkstra(int x) {
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // 최소 힙

    dist[A] = 0;      // 시작점 초기화
    pq.push({0, A});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d < dist[u]) continue;  // 이미 더 짧은 경로
        if (d > C) continue;        // 예산 초과
        if (u == B) return true;    // 도착

        for (auto [v, w] : graph[u]) {
            if (w > x) continue;

            if (d + w < dist[v]) {  // 더 짧은 경로
                dist[v] = d + w;    // 갱신
                pq.push({d + w, v});
            }
        }
    }

    return dist[B] <= C;  // 최종적으로 예산 내에 가능 여부
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> A >> B >> C;

    graph.assign(N + 1, {});
    int maxW = 0;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        maxW = max(maxW, w);
    }

    int l = 0, r = maxW;
    int res = -1;

    while (l <= r) {  // 이분 탐색
        int mid = (l + r) / 2;  // 최대 간선 후보

        if (dijkstra(mid)) {  // 가능
            res = mid;
            r = mid - 1;
        } else {              // 불가능
            l = mid + 1;
        }
    }

    cout << res << '\n';

    return 0;
}
