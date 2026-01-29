#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int> indeg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    graph.assign(N + 1, {});
    indeg.assign(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b); // a가 b보다 앞에 서야 함
        indeg[b]++;            // b의 진입차수 증가
    }

    queue<int> q;

    // 처음에 줄 설 수 있는 학생들 (진입차수 0)
    for (int i = 1; i <= N; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << ' '; // 현재 학생 출력

        // cur 뒤에 서야 하는 학생들 처리
        for (int nxt : graph[cur]) {
            indeg[nxt]--;          // 선행 조건 하나 해결
            if (indeg[nxt] == 0) { // 이제 줄 설 수 있음
                q.push(nxt);
            }
        }
    }

    cout << '\n';
    
    return 0;
}
