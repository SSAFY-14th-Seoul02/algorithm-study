#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M, res;
vector<string> g;
vector<vector<int>> state;  // 0 : 미방문, 1 : 방문 중, 2 : 방문 완료

// 방향 문자에 따라 행 이동
int dr(char c) {
    if (c == 'U') return -1;
    if (c == 'D') return 1;

    return 0;
}

// 방향 문자에 따라 열 이동
int dc(char c) {
    if (c == 'L') return -1;
    if (c == 'R') return 1;
    return 0;
}

void dfs(int r, int c) {
    state[r][c] = 1;

    int nr = r + dr(g[r][c]);
    int nc = c + dc(g[r][c]);

    if (state[nr][nc] == 0) {
        // 아직 방문하지 않은 칸이면 계속 탐색
        dfs(nr, nc);
    } else if (state[nr][nc] == 1) {
        // 현재 DFS 경로 안에서 다시 만남 → 사이클 발견
        // 사이클 하나 = 안전구역 하나
        res++;
    }

    state[r][c] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    g.assign(N, "");
    for (int i = 0; i < N; i++) {
        cin >> g[i];
    }

    state.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 아직 방문하지 않은 칸이면 탐색 시작
            if (state[i][j] == 0) dfs(i, j);
        }
    }

    cout << res << '\n';

    return 0;
}