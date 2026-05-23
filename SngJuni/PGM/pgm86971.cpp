#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;

int bfs(int start, int u, int v, int n) {
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    int cnt = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : graph[cur]) {
            if ((cur == u && next == v) || (cur == v && next == u)) continue;

            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    graph.assign(n + 1, {});

    for (auto& w : wires) {
        int a = w[0];
        int b = w[1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (auto& w : wires) {
        int a = bfs(w[0], w[0], w[1], n);
        int b = n - a;

        answer = min(answer, abs(a - b));
    }

    return answer;
}
