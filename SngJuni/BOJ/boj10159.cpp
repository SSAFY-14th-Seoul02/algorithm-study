#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<vector<int>> rgraph;

int dfs(int x, vector<vector<int>> &g, vector<bool> &visited) {
    int cnt = 0;

    for (auto i : g[x]) {
        if (visited[i]) continue;
        visited[i] = true;
        cnt++;
        cnt += dfs(i, g, visited);
    }

    return cnt;  // 비교 가능한 물건의 개수
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    graph.assign(N + 1, {});
    rgraph.assign(N + 1, {});

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);   // 정방향
        rgraph[v].push_back(u);  // 역방향
    }

    for (int i = 1; i <= N; i++) {
        vector<bool> visited_1(N + 1, false);
        vector<bool> visited_2(N + 1, false);

        visited_1[i] = true;
        visited_2[i] = true;

        int lighter = dfs(i, graph, visited_1);
        int heavier = dfs(i, rgraph, visited_2);

        cout << (N - 1 - (lighter + heavier)) << '\n';
    }

    return 0;
}