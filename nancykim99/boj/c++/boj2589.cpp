/*
BOJ2589 : 보물섬 (G5)

해결 방법 : bfs로 L을 다 돌려 max 거리를 찾은 후, 저장. 저장한 것들 중에서 max를 찾기.
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int n, m;
vector<string> grid;

int bfs(int si, int sj) {
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;

    q.push({si, sj});
    dist[si][sj] = 0;

    int best = 0;
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int i = cur.first;
        int j = cur.second;

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (0 <= ni && ni < n && 0 <= nj && nj < m
                && grid[ni][nj] == 'L'
                && dist[ni][nj] == -1) {

                dist[ni][nj] = dist[i][j] + 1;
                best = max(best, dist[ni][nj]);
                q.push({ni, nj});
            }
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'L') {
                ans = max(ans, bfs(i, j));
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
