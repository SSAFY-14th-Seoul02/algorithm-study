#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, H, W, Sr, Sc,Fr, Fc;
int res = -1;
vector<vector<int>> psum;
vector<vector<int>> dist;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(Sr, Sc);
    dist[Sr][Sc] = 0;  // 시작점 초기화

    while (!q.empty()) {
        auto [r1, c1] = q.front();  // 좌상단 좌표
        q.pop();

        if (r1 == Fr && c1 == Fc) {  // 도착 좌표 도착
            res = dist[r1][c1];
            return;
        }

        for (int k = 0; k < 4; k++) {
            int nr1 = r1 + dy[k];  // 새로운 좌상단 좌표
            int nc1 = c1 + dx[k];

            if (nr1 < 1 || nr1 >= N - H + 2 || nc1 < 1 || nc1 >= M - W + 2) continue;  // 범위 바깥
            if (dist[nr1][nc1] != -1) continue;  // 이미 방문

            int r2 = nr1 + H - 1;  // 우하단 좌표
            int c2 = nc1 + W - 1;

            int w = psum[r2][c2]  // (nr1, nr2) 로 이동 시, 직사각형 내에 벽 갯수
                  - psum[nr1 - 1][c2]
                  - psum[r2][nc1 - 1]
                  + psum[nr1 - 1][nc1 - 1];
            
            if (w == 0) {  // 벽 갯수가 0이어야 해당 좌표로 이동 가능
                q.emplace(nr1, nc1);
                dist[nr1][nc1] = dist[r1][c1] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    psum.assign(N + 1, vector<int>(M + 1, 0));
    dist.assign(N + 1, vector<int>(M + 1, -1));

    for (int i = 1; i <= N; i++) {  // 벽 누적합
        for (int j = 1; j <= M; j++) {
            int x;
            cin >> x;

            psum[i][j] = x
                       + psum[i - 1][j]
                       + psum[i][j - 1]
                       - psum[i - 1][j - 1];
        }
    }

    cin >> H >> W >> Sr >> Sc >> Fr >> Fc;

    bfs();

    cout << res << '\n';

    return 0;
}