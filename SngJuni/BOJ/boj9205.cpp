#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

int n;
vector<pair<int,int>> p;   // {x, y}
vector<int> visited;

int dist(const pair<int,int>& a, const pair<int,int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool bfs() {
    int sz = (int)p.size();
    visited.assign(sz, 0);

    queue<int> q;
    q.push(0);            // 집부터 시작
    visited[0] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == sz - 1) return true; // 락페 도착

        for (int nxt = 0; nxt < sz; nxt++) {
            if (visited[nxt]) continue;
            if (dist(p[cur], p[nxt]) <= 1000) {
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> n;

        // 0: 집, 1~n: 편의점, n+1: 락페
        p.assign(n + 2, {0, 0});

        cin >> p[0].first >> p[0].second;   // 집

        for (int i = 1; i <= n; i++) {
            cin >> p[i].first >> p[i].second; // 편의점
        }

        cin >> p[n + 1].first >> p[n + 1].second; // 락페

        cout << (bfs() ? "happy\n" : "sad\n");
    }

    return 0;
}
