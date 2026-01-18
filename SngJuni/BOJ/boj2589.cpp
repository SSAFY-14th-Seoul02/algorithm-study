#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N, M, res;
vector<vector<char>> board;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int y, int x) {
    vector<vector<int>> dist(N, vector<int>(M, -1));

    int cnt = 0;  // 보물이 묻혀 있을 두 곳 간의 최단거리
    queue<pair<int, int>> q;
    q.emplace(y, x);
    dist[y][x] = 0;

    while (!q.empty()) {
        auto [cy, cx] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;  // 범위 바깥
            if (dist[ny][nx] == -1 && board[ny][nx] == 'L') {      // 아직 방문하지 않은 육지일 경우에만 탐색 진행
                q.emplace(ny, nx);
                dist[ny][nx] = dist[cy][cx] + 1;
                cnt = dist[ny][nx];
            }
        }
    }

    return cnt;  // 현재 출발 육지에서 제일 먼 육지까지의 최단 거리
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    board.assign(N, vector<char>(M, 0));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = s[j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'L') {  // 육지에서만 BFS 탐색 시작
                int temp = bfs(i, j);
                res = max(res, temp);  // 보물이 묻혀 있는 후보지 두 곳 간의 최단 거리의 최댓값 갱신
            }
        }
    }

    cout << res << '\n';  // 결과 출력

    return 0;
}