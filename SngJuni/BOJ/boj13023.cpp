#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> arr;
vector<bool> visited;
int flag = 0;

void dfs(int i, int depth) {
    if (flag) return;

    if (depth == 4) {
        flag = 1;
        return;
    }

    for (auto j : arr[i]) {     // 현재 정점과 연결된 모든 정점 탐색
        if (!visited[j]) {
            visited[j] = true;
            dfs(j, depth + 1);
            visited[j] = false; // 백트래킹
        }
        if (flag) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;

    arr.assign(n, {});
    visited.assign(n, false);
    
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a].push_back(b);  // 무방향 그래프
        arr[b].push_back(a);
    }

    // 모든 정점을 시작점으로 DFS 탐색
    for (int i = 0; i < n; i++) {
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;  // 백트래킹
        if (flag) break;    
    }

    cout << flag << '\n';

    return 0;
}