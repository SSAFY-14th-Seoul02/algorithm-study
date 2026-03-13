#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C;
vector<string> board;

int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};

pair<int, int> moveRobot(int rx, int ry, int sx, int sy) {
    if (rx < sx) rx++;
    else if (rx > sx) rx--;

    if (ry < sy) ry++;
    else if (ry > sy) ry--;

    return {rx, ry};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;

    board.assign(R, "");
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }

    int sx = 0, sy = 0;
    vector<pair<int, int>> robots;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'I') {
                sx = j;
                sy = i;
            }
            else if (board[i][j] == 'R') {
                robots.push_back({j, i});
            }
        }
    }

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        int dir = s[i] - '1';

        sx += dx[dir];
        sy += dy[dir];

        // 종수가 이동한 칸에 아두이노가 있으면 종료
        for (auto [rx, ry] : robots) {
            if (rx == sx && ry == sy) {
                cout << "kraj " << i + 1 << '\n';
                return 0;
            }
        }

        // 아두이노 다음 위치 계산
        vector<pair<int, int>> nextPos;
        vector<vector<int>> cnt(R, vector<int>(C, 0));

        for (auto [rx, ry] : robots) {
            auto [nrx, nry] = moveRobot(rx, ry, sx, sy);

            // 아두이노가 종수에게 도달하면 종료
            if (nrx == sx && nry == sy) {
                cout << "kraj " << i + 1 << '\n';
                return 0;
            }

            nextPos.push_back({nrx, nry});
            cnt[nry][nrx]++;
        }

        // 충돌 안 난 아두이노만 생존
        vector<pair<int, int>> nextRobots;
        for (auto [rx, ry] : nextPos) {
            if (cnt[ry][rx] == 1) {
                nextRobots.push_back({rx, ry});
            }
        }

        robots = nextRobots;
    }

    // 최종 보드 생성
    vector<string> result(R, string(C, '.'));
    result[sy][sx] = 'I';

    for (auto [rx, ry] : robots) {
        result[ry][rx] = 'R';
    }

    for (int i = 0; i < R; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}