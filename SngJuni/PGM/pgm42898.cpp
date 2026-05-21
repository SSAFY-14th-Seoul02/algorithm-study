#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (auto p : puddles) {
        int x = p[0];
        int y = p[1];
        dp[y][x] = -1;
    }

    dp[1][1] = 1;

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (dp[y][x] == -1) {
                dp[y][x] = 0;
                continue;
            }

            if (y == 1 && x == 1) continue;

            dp[y][x] = (dp[y - 1][x] + dp[y][x - 1]) % 1000000007;
        }
    }

    return dp[n][m];
}