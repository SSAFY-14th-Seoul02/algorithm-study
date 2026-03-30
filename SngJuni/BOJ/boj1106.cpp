#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, N;
    cin >> C >> N;

    vector<pair<int, int>> arr(N);  // (비용, 고객 수)
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    vector<int> dp(C + 101, INT_MAX);  // dp[i] = 고객 i명을 확보하는 데 필요한 최소 비용
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        int cost = arr[i].first;
        int customers = arr[i].second;

        // 이전 상태가 유효할 때만 갱신
        for (int j = customers; j <= C + 100; j++) {
            if (dp[j - customers] != INT_MAX) {
                // 현재 광고를 한 번 더 사용하는 경우
                dp[j] = min(dp[j], dp[j - customers] + cost);
            }
        }
    }

    int res = INT_MAX;

    // 정확히 C명이 아니라 "C 이상" 중 최소 비용 선택
    for (int i = C; i <= C + 100; i++) {
        res = min(res, dp[i]);
    }

    cout << res << '\n';

    return 0;
}