#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> arr(N);  // 초밥 번호를 위한 배열
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> cnt(d + 1, 0);  // 현재 윈도우에 있는 초밥 x의 갯수
    int distinct = 0;           // 현재 윈도우에 있는 서로 다른 초밥 종류의 수

    for (int i = 0; i < k; i++) {
        int x = arr[i];
        if (cnt[x]++ == 0) distinct++;
    }

    int res = 0;  // 서로 다른 초밥 종류 수의 최댓값

    // 슬라이딩 윈도우
    for (int start = 0; start < N; start++) {
        int cur = distinct;
        if (cnt[c] == 0) {  // 쿠폰 초밥이 현재 윈도우에 없다면
            cur++;
        }
        res = max(res, cur);  // 최댓값 갱신

        int out = arr[start];  // 윈도우에서 빠질 접시의 초밥 종류
        if (--cnt[out] == 0) distinct--;

        int in = arr[(start + k) % N];  // 새로 윈도우에 들어올 접시
        if (cnt[in]++ == 0) distinct++;
    }

    cout << res << "\n";

    return 0;
}
