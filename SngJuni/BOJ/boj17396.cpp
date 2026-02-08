#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M;
vector<int> watch;
vector<vector<pair<int,int>>> graph;
vector<long long> dist;

void dijkstra() {
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();

        if (d > dist[cur]) continue;

        for (auto e : graph[cur]) {
            int to = e.first;
            int w = e.second;

            // 감시 중인 곳은 들어가면 안 됨 (단, 도착점은 예외)
            if (to != N - 1 && watch[to] == 1) continue;

            if (dist[to] > dist[cur] + (long long)w) {
                dist[to] = dist[cur] + (long long)w;
                pq.emplace(dist[to], to);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    watch.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> watch[i];
    }
    
    graph.assign(N, {});
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        // 시작점/도착점 제외 감시 노드 처리를 다익스트라에서 하므로 여기서는 그대로 추가
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
    }

    dist.assign(N, LLONG_MAX);

    // 시작점이 감시 상태인 경우는 입력상 의미 없지만, 안전하게 처리 가능
    if (0 != N - 1 && watch[0] == 1) {
        cout << -1 << '\n';
        return 0;
    }

    dijkstra();

    if (dist[N - 1] == LLONG_MAX) cout << -1 << '\n';
    else cout << dist[N - 1] << '\n';

    return 0;
}
