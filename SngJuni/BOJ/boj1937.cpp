#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, res;
vector<vector<int>> arr;  // 대나무 정보
vector<vector<int>> dp;   // (y, x) 에서 시작했을 때 판다의 최대 생존 일수

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int dfs(int y, int x) {
    if (dp[y][x] != 0) return dp[y][x];

    // 현재 칸
    dp[y][x] = 1;

    for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;  // 범위 바깥
        if (arr[ny][nx] > arr[y][x]) {
            dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
        }
    }

    return dp[y][x];  // (y, x) 에서 시작했을 때 판다가 살 수 있는 최대 일수 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    arr.assign(n, vector<int>(n, 0));
    dp.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // 모든 칸에서 DFS 탐색
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, dfs(i, j));
        }
    }

    cout << res << '\n';

    return 0;
}