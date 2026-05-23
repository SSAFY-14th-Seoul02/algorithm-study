#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int board[102][102];
int dist[102][102];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct Node {
    int y;
    int x;
};

int bfs(int sy, int sx, int ey, int ex) {
    queue<Node> q;

    q.push({sy, sx});
    dist[sy][sx] = 1;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        int y = cur.y;
        int x = cur.x;

        if (y == ey && x == ex) {
            return (dist[y][x] - 1) / 2;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= 102 || nx < 0 || nx >= 102) continue;
            if (board[ny][nx] != 1) continue;
            if (dist[ny][nx] != 0) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    return 0;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for (auto rect : rectangle) {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;

        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                if (y == y1 || y == y2 || x == x1 || x == x2) {
                    if (board[y][x] != 2) {
                        board[y][x] = 1;
                    }
                } else {
                    board[y][x] = 2;
                }
            }
        }
    }

    int sy = characterY * 2;
    int sx = characterX * 2;
    int ey = itemY * 2;
    int ex = itemX * 2;

    return bfs(sy, sx, ey, ex);
}