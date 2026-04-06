#include <iostream>
#include <vector>

using namespace std;

int N, M, res;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int start) {
    visited[start] = true;
    res++;

    for (auto i : graph[start]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    graph.assign(N + 1, {});
    visited.assign(N + 1, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    cout << res - 1 << '\n';

    return 0;
}