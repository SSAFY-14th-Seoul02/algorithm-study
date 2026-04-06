#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M, K;
vector<string> board;

int dx[4] = {0, 0, -1 ,1};
int dy[4] = {-1, 1, 0, 0};

struct Node {  // (x, y) 에 broken 개의 벽을 부수고 도달.
    int y;
    int x;
    int broken;
};

int bfs() {
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(K + 1, 0)));  // 최단 거리
    queue<Node> q;

    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        int y = cur.y;
        int x = cur.x;
        int broken = cur.broken;

        if (x == M - 1 && y == N - 1) {  // (M, N) 에 도착
            return dist[y][x][broken];   // 최단거리 반환
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

            if (board[ny][nx] == '0') {  // 벽이 아닐 때
                if (dist[ny][nx][broken] == 0) {
                    q.push({ny, nx, broken});
                    dist[ny][nx][broken] = dist[y][x][broken] + 1;
                }
            } else {  // 벽이 있을 때
                if (broken < K && dist[ny][nx][broken + 1] == 0) {  // K개 이하의 벽을 부수고 해당 칸으로 이동 가능할 때
                    q.push({ny, nx, broken + 1});
                    dist[ny][nx][broken + 1] = dist[y][x][broken] + 1;
                }
            }
        }
    }

    return -1;  // 도달 불가능
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    board.assign(N, "");
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    cout << bfs() << '\n';

    return 0;
}