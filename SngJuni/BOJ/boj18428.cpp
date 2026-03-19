#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, flag;
vector<vector<char>> board;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool check() {  // 학생 감시 가능 여부 확인
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'T') {
                for (int k = 0; k < 4; k++) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];

                    while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                        if (board[ny][nx] == 'S') return false;
                        if (board[ny][nx] == 'O') break;
                        nx += dx[k];
                        ny += dy[k];
                    }
                }
            }
        }
    }
    return true;
}

void dfs(int r, int c, int cnt) {
    if (flag) return;

    if (cnt == 3) {  // 장애물 3개 설치
        if (check()) flag = 1;
        return;
    }

    for (int i = r; i < N; i++) {
        for (int j = (i == r ? c : 0); j < N; j++) {
            if (board[i][j] == 'X') {
                board[i][j] = 'O';
                dfs(i, j, cnt + 1);
                board[i][j] = 'X';  // 백트래킹
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    
    board.assign(N, vector<char>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, 0);

    cout << (flag ? "YES" : "NO") << "\n";

    return 0;
}