#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
vector<string> grid;
// dist[y][x][b] : (y, x)에 b(0 = 안부숨,1 = 부숨) 상태로 도달한 최단거리
vector<vector<vector<int>>> dist;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs() {
    queue<pair<pair<int,int>, int>> q;
    q.push({{0, 0}, 0});    // 시작점, 아직 벽 안 부숨
    dist[0][0][0] = 1;      // 시작 거리 1

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int b = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            // 빈 칸이면 같은 상태(b)로 이동
            if (grid[ny][nx] == '0') {
                if (dist[ny][nx][b] == 0) {
                    dist[ny][nx][b] = dist[y][x][b] + 1;
                    q.push({{ny, nx}, b});
                }
            }

            // 벽이고 아직 안 부쉈다면, 벽을 부수고 상태 변경
            else if (b == 0 && dist[ny][nx][1] == 0) {
                dist[ny][nx][1] = dist[y][x][b] + 1;
                q.push({{ny, nx}, 1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    grid.assign(N, "");
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    // 방문 여부 + 거리 저장용 dist 초기화
    dist.assign(N, vector<vector<int>>(M, vector<int>(2, 0)));

    bfs();

    int a = dist[N - 1][M - 1][0];  // 벽 안 부수고 도착
    int b = dist[N - 1][M - 1][1];  // 벽 부수고 도착

    // 둘 다 불가능하면 -1, 아니면 가능한 것 중 최솟값
    if (a == 0 && b == 0) cout << -1 << '\n';
    else if (a == 0) cout << b << '\n';
    else if (b == 0) cout << a << '\n';
    else cout << min(a, b) << '\n';

    return 0;
}
