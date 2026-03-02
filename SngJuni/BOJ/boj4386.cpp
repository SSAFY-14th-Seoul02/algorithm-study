// Prim 알고리즘
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>
#include <cfloat>

using namespace std;

int N;
vector<pair<double, double>> star;

double prim() {
    vector<double> dist(N, DBL_MAX);  // 현재 MST에 정점 v를 연결하는 최소 간선 비용
    vector<bool> used(N, false);      // v가 MST에 포함되어 있는지 여부

    // (간선 비용, 정점) 을 비용 기준으로 최소 힙으로 저장
    priority_queue<pair<double, int>, 
                   vector<pair<double, int>>, 
                   greater<pair<double, int>>> pq;

    // 0번 정점에서 시작
    dist[0] = 0;
    pq.push({0, 0});

    double res = 0;
    int cnt = 0;

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (used[u]) continue;  // 이미 포함된 정점
        
        used[u] = true;  // u 추가
        res += cost;

        if (++cnt == N) break;  // 모든 별 연결되면 종료

        for (int v = 0; v < N; v++) {  // u를 통해서 v를 더 싸게 갈 수 있다면 갱신
            if (used[v]) continue;

            double dx = star[u].first - star[v].first;
            double dy = star[u].second - star[v].second;
            double w = sqrt(dx * dx + dy * dy);

            if (w < dist[v]) {  // v를 MST에 연결하는 최소 비용 갱신
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    star.assign(N, {});

    for (int i = 0; i < N; i++) {
        cin >> star[i].first >> star[i].second;
    }

    double res = prim();

    cout << fixed;
    cout.precision(2);
    cout << res << '\n';

    return 0;
}


// Kruskal 알고리즘
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int parent[101];

int find_set(int x) {
    if (parent[x] == x) return x;

    return parent[x] = find_set(parent[x]);
}

void union_set(int a, int b) {
    int ra = find_set(a);
    int rb = find_set(b);

    if (ra != rb) parent[rb] = ra;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<double, double>> star(N);
    for (int i = 0; i < N; i++) {
        cin >> star[i].first >> star[i].second;
    }

    vector<pair<double, pair<int, int>>> edges;  // 모든 간선 : (cost, (u, v))

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double dx = star[i].first - star[j].first;
            double dy = star[i].second - star[j].second;
            double dist = sqrt(dx * dx + dy * dy);

            edges.push_back({dist, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());  // 거리 기준 오름차순 정렬

    iota(parent, parent + N, 0);

    double res = 0;
    int cnt = 0;

    for (auto& i : edges) {
        double cost = i.first;
        int u = i.second.first;
        int v = i.second.second;

        if (find_set(u) != find_set(v)) {  // 같은 집합 아니면
            union_set(u, v);               // 합침.
            res += cost;
            cnt++;

            if (cnt == N - 1) break;  // 모든 별 연결되면 종료
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << res << '\n';

    return 0;
}