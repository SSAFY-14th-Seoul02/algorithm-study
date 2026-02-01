#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

int N, M;
int S, E;
vector<vector<pair<int,int>>> graph;
vector<long long> dist;
vector<int> parent;

void dijkstra() {
    // {거리, 정점} 최소 힙
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [d, cur] = pq.top();  // 현재까지의 거리와 정점
        pq.pop();

        if (d > dist[cur]) continue;  // 이미 더 짧은 경로가 있으면 무시

        for (auto nxt : graph[cur]) {
            auto [to, w] = nxt;

            // 더 짧은 경로 발견 시 갱신
            if (dist[to] > dist[cur] + w) {
                dist[to] = dist[cur] + w;
                pq.push({dist[to], to});
                parent[to] = cur;  // 경로 복원을 위해 이전 정점 저장
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
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});  // 단방향 간선 저장
    }

    cin >> S >> E;

    dist.assign(N + 1, LLONG_MAX);  // 거리 배열 초기화
    parent.assign(N + 1, 0);

    dijkstra();  // 다익스트라

    vector<int> path;  // 최단 경로 저장
    for (int v = E; v != 0; v = parent[v]) {
        path.push_back(v);
        if (v == S) break;
    }
    reverse(path.begin(), path.end());  // 순서 뒤집기

    cout << dist[E] << '\n';      // 최소 비용 출력
    cout << path.size() << '\n';  // 경로에 포함된 도시 수

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << (i + 1 == path.size() ? '\n' : ' ');
    }

    return 0;
}
