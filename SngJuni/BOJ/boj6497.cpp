#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int parent[200001];

int find_set(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);
}

bool union_set(int a, int b) {
    int ra = find_set(a);
    int rb = find_set(b);

    if (ra == rb) return false;
    parent[rb] = ra;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;

    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0) break;

        vector<pair<int, pair<int,int>>> edges;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;

            total += z;
            edges.push_back({z, {x, y}});
        }

        sort(edges.begin(), edges.end());  // 비용 기준 오름차순 정렬

        iota(parent, parent + m, 0);

        long long mst = 0;
        int cnt = 0;

        for (auto &e : edges) {
            int cost = e.first;
            int u = e.second.first;
            int v = e.second.second;

            if (union_set(u, v)) {
                mst += cost;
                if (++cnt == m - 1) break;
            }
        }

        cout << total - mst << '\n';
    }

    return 0;
}