#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int l = 0, r = 0;   // 현재 구간 [l, r)
    int sum = 0;        // 현재 구간 합
    int res = INT_MAX;  // 조건을 만족하는 최소 길이

    while (true) {
        if (sum >= S) {             // 현재 구간 합이 S 이상이면
            res = min(res, r - l);  // 길이를 갱신하고 왼쪽 포인터를 이동해 구간을 줄임
            sum -= arr[l];
            l++;
        } else if (r == N) {
            break;
        } else {                    // 구간 합이 부족하면 오른쪽 포인터 확장
            sum += arr[r];
            r++;
        }
    }

    cout << (res == INT_MAX ? 0 : res) << '\n';

    return 0;
}