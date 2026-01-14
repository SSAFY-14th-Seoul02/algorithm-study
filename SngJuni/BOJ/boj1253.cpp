#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }


    // 투포인터 사용을 위해서 정렬
    sort(arr.begin(), arr.end());

    int res = 0;

    for (int i = 0; i < N; i++) {
        int tar = arr[i];
        int l = 0, r = N - 1;
        bool flag = false;

        // l, r 투포인터로 두 수의 합 탐색
        while (l < r) {
            // 자기 자신은 스킵
            if (l == i) {
                l++;
                continue;
            }
            if (r == i) {
                r--;
                continue;
            }

            int sum = arr[l] + arr[r];

            if (sum == tar) {  // 서로 다른 두 수의 합으로 tar 만들 수 있을 때
                flag = true;
                break;
            } else if (sum < tar) {
                l++;
            } else {
                r--;
            }
        }

        if (flag) res++;
    }

    cout << res << "\n";  // 결과 출력

    return 0;
}
