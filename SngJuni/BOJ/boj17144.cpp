#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, T, res;
    cin >> R >> C >> T;

    int fx1 = 0, fx2 = 0, fy1, fy2;
    vector<vector<int>> board(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) {  // 공기청정기 아래쪽 y 좌표
                fy2 = i;
            }
        }
    }
    fy1 = fy2 - 1;  // 공기청정기 위쪽 y 좌표

    while (T--) {
        // 1. 미세먼지 확산
        vector<vector<int>> board_copy = board;  // 미세먼지 확산 처리해줄 원본 board의 복사본
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == 0) continue;
                
                int dust = board[i][j] / 5;  // 확산될 미세먼지 양
                int cnt = 0;  // 확산된 칸 갯수
                for (int k = 0; k < 4; k++) {
                    int ni = i + dy[k];
                    int nj = j + dx[k];

                    if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;  // 칸 바깥
                    if ((ni == fy1 && nj == 0) || (ni == fy2 && nj == 0)) continue;  // 인접 방향에 공기청정기
                    
                    board_copy[ni][nj] += dust;
                    cnt++;
                }
                board_copy[i][j] -= dust * cnt;  // 미세먼지 확산된 상태로 원본 배열 수정
            }
        }

        board = board_copy;

        // 2. 공기청정기 작동
        // 위쪽 공기 청정기
        for (int i = fy1 - 1; i > 0; i--) {
            board[i][0] = board[i - 1][0];
        }
        for (int j = 0; j < C - 1; j++) {
            board[0][j] = board[0][j + 1];
        }
        for (int i = 0; i < fy1; i++) {
            board[i][C - 1] = board[i + 1][C - 1];
        }
        for (int j = C - 1; j > 1; j--) {
            board[fy1][j] = board[fy1][j - 1];
        }
        board[fy1][1] = 0;

        // 아래쪽 공기 청정기
        for (int i = fy2 + 1; i < R - 1; i++) {
            board[i][0] = board[i + 1][0];
        }
        for (int j = 0; j < C - 1; j++) {
            board[R - 1][j] = board[R - 1][j + 1];
        }
        for (int i = R - 1; i > fy2; i--) {
            board[i][C - 1] = board[i - 1][C - 1];
        }
        for (int j = C - 1; j > 1; j--) {
            board[fy2][j] = board[fy2][j - 1];
        }
        board[fy2][1] = 0;

        board[fy1][0] = -1;  // 미세먼지 확산시에 공기청정기 값 바뀔 경우 다시 -1로 복원
        board[fy2][0] = -1;

        res = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                res += board[i][j];
            }
        }
        res += 2;
    }

    cout << res << '\n';

    return 0;
}