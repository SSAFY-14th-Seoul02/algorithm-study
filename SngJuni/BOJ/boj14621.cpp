#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<char> gender;
vector<int> parent;
vector<pair<int, pair<int,int>>> edges;

// Union-Find: 루트 찾기 (경로 압축)
int find(int x) {
    if (parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}

// Union-Find: 두 집합 합치기
bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;

    parent[b] = a;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    gender.assign(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> gender[i];
    }

    edges.assign(M, {0, {0, 0}});

    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        // 성별이 다른 학교끼리만 간선으로 사용
        if (gender[u] != gender[v]) {
            edges.push_back({d, {u, v}});
        }
    }

    // 거리 기준 오름차순 정렬  
    sort(edges.begin(), edges.end());

    parent.assign(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    
    int cost = 0, cnt = 0;
    for (auto &e : edges) {
        int d = e.first;
        int u = e.second.first;
        int v = e.second.second;

        if (unite(u, v)) {
            cost += d;
            cnt++;

            if (cnt == N - 1) break;
        }
    }

    // 모든 정점을 연결하지 못한 경우
    if (cnt != N - 1) cout << -1 << '\n';
    else cout << cost << '\n';

    return 0;
}
