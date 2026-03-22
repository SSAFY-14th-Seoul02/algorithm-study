#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, res;
vector<pair<int,int>> sw[101][101];

bool light[101][101];
bool visited[101][101];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs() {
    queue<pair<int,int>> q;
    q.push({1,1});
    visited[1][1] = true;
    light[1][1] = true;
    res = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        // 1. 스위치 작동
        for (auto& p : sw[x][y]) {
            int nx = p.first;
            int ny = p.second;
            if (!light[nx][ny]) {
                light[nx][ny] = true;
                res++;

                // 인접 방문 가능하면 바로 이동
                for (int d = 0; d < 4; d++) {
                    int px = nx + dx[d];
                    int py = ny + dy[d];
                    if (px >= 1 && px <= N && py >= 1 && py <= N && visited[px][py]) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        break;
                    }
                }
            }
        }

        // 2. 이동
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (!light[nx][ny] || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        sw[x][y].push_back({a, b});
    }

    bfs();

    cout << res << '\n';

    return 0;
}