#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, M, res;
vector<vector<int>> board;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// 높이 h 기준으로 h보다 낮은 영역 을 BFS로 탐색
void bfs(int x, int y, int h, vector<vector<bool>>& v) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> component;  // 같은 영역에 속한 칸들
    bool isPool = true;                // 둘러싸여 있는지

    q.push({x, y});
    v[x][y] = true;
    component.push_back({x, y});

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        // 가장 바깥쪽 영역이면
        if (cx == 0 || cx == N - 1 || cy == 0 || cy == M - 1) {
            isPool = false;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                // 방문하지 않은 영역이 h보다 낮은 영역이면
                if (!v[nx][ny] && board[nx][ny] < h) {
                    v[nx][ny] = true;
                    q.push({nx, ny});
                    component.push_back({nx, ny});
                }
            } else {
                // 가장 바깥쪽 영역이면
                isPool = false;
            }
        }
    }

    if (isPool) {  // 둘러싸여 있는 영역
        for (auto& p : component) {
            board[p.first][p.second]++;  // 높이 1 증가
            res++;                       // 채운 물의 양 1 증가
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    board.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    // 높이 2 ~ 9까지
    for (int h = 2; h <= 9; h++) {
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // h보다 낮은 영역이면서 방문하지 않은 영역이면
                if (board[i][j] < h && !visited[i][j]) {
                    bfs(i, j, h, visited);
                }
            }
        }
    }

    cout << res << '\n';

    return 0;
}