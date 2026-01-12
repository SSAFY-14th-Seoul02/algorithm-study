#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;

vector<vector<int>> tree;  // 트리
vector<bool> visited;      // 방문 배열
vector<int> dp;            // dp 배열

void dfs(int root) {
    if (visited[root]) {
        return;
    }

    visited[root] = true;
    dp[root] = 1;  // 루트 자신 포함

    for (auto& i : tree[root]) {  // 자식 노드 순회
        if (!visited[i]) {
            dfs(i);
            dp[root] += dp[i];  // 서브트리에 속한 정점의 수 더하기
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> Q;

    tree.assign(N + 1, {});
    visited.assign(N + 1, false);
    dp.assign(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(R);  // 재귀적으로 탐색

    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        cout << dp[x] << '\n';
    }

    return 0;
}