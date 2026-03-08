#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int N, M;
vector<string> grid;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<vector<int>> bfs(int sr, int sc) {
    // dist[r][c] : 시작점(sr, sc)에서 (r,c)까지의 최단 거리
    vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
    queue<pair<int,int>> q;

    dist[sr][sc] = 0;
    q.push({sr, sc});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nr = r + dx[k];
            int nc = c + dy[k];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (grid[nr][nc] == 'D') continue;
            if (dist[nr][nc] != INT_MAX) continue;

            // 최단 거리 갱신
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    return dist;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    grid.assign(N, "");
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    
    int sr = -1, sc = -1;
    int hr = -1, hc = -1;

    // S(시작점)과 H(집) 위치 찾기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 'S') {
                sr = i; sc = j;
            }
            if (grid[i][j] == 'H') {
                hr = i; hc = j;
            }
        }
    }

    auto distS = bfs(sr, sc);  // S에서 모든 칸까지 최단 거리
    auto distH = bfs(hr, hc);  // H에서 모든 칸까지 최단 거리

    int res = INT_MAX;

    // 모든 F에 대해 최소값 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] != 'F') continue;
            if (distS[i][j] == INT_MAX || distH[i][j] == INT_MAX) continue;

            res = min(res, distS[i][j] + distH[i][j]);
        }
    }

    // 가능한 경로가 없으면 -1
    cout << (res == INT_MAX ? -1 : res) << '\n';

  return 0;
}