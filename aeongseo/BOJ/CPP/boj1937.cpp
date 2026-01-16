/*** 1937. 욕심쟁이 판다 ***/

/*
    dp 테이블에 값이 채워져 있으면 그 값 반환
    채워져 있지 않으면 4방향 탐색하면서 자신보다 대나무가 많은 칸으로 이동
    이동한 칸에서의 최대 이동 거리 + 1과 현재 dp 테이블의 값을 비교하여 큰 값으로 갱신
    모든 칸에 대해 최대 이동 거리 계산 후 그 중 최댓값 출력
    -> 큰 값에서 작은 값으로 이동하는 것!
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> bamboo, dp;
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
int n, ans = 0;

int move(int i, int j);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	bamboo.assign(n+1, vector<int>(n+1, 0));
	dp.assign(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> bamboo[i][j];
		}
	}

	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < n + 1; j++) {
			ans = max(ans, move(i, j));
		}
	}
	
	cout << ans;

	return 0;
}

int move(int i, int j) {
	if (dp[i][j]) return dp[i][j];

	dp[i][j] = 1;

	int ni, nj, max_dist = 0;
	for (int d = 0; d < 4; d++) {
		ni = i + di[d];
		nj = j + dj[d];

		if (ni <= 0 || ni > n || nj <= 0 || nj > n) continue;
		if(bamboo[ni][nj] > bamboo[i][j]) dp[i][j] = max(dp[i][j], move(ni, nj) + 1);
	}

	return dp[i][j];
}