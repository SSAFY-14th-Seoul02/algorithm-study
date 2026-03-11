#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> dp(N, 1); // dp[i] = i번째 원소를 마지막으로 하는 LIS 길이

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            // 앞의 값이 더 작으면 LIS에 이어붙일 수 있음
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 전체 LIS 길이
    int lis = *max_element(dp.begin(), dp.end());

    // 제거해야 할 최소 원소 개수
    cout << N - lis << '\n';

    return 0;
}