#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M;
vector<vector<pair<int,int>>> graph;
vector<long long> dist;

void dijkstra() {
    // {거리, 정점} 형태의 최소 힙
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[1] = 0;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();

        if (d > dist[cur]) continue;  // 이미 더 짧은 경로가 있으면 무시

        for (auto i : graph[cur]) {  // cur에서 갈 수 있는 모든 인접 정점 탐색
            auto [to, w] = i;

            if (dist[to] > dist[cur] + w) {
                dist[to] = dist[cur] + w;  // 최소 거리 갱신
                pq.emplace(dist[to], to);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    graph.assign(N + 1, {});
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].emplace_back(b, c);  // 양방향 간선 저장
        graph[b].emplace_back(a, c);
    }

    dist.assign(N + 1, LLONG_MAX);

    dijkstra();  // 다익스트라

    cout << dist[N] << '\n';

    return 0;
}