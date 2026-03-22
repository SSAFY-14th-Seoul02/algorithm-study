#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
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

    sort(arr.begin(), arr.end());  // 특성값 기준 오름차순 정렬

    int l = 0, r = N - 1;
    int a = 0, b = 0;
    int temp = INT_MAX;

    while (l < r) {  // 투 포인터
        int sum = arr[l] + arr[r];  // 두 특성값의 합

        if (sum == 0) {  // 합이 0인 경우
            a = arr[l];
            b = arr[r];
            break;
        }
        if (abs(sum) < temp) {  // 합이 0에 가까운 경우
            temp = abs(sum);
            a = arr[l];
            b = arr[r];
        }
        if (sum < 0) {  // 합이 0보다 작은 경우
            l++;
        } else {  // 합이 0보다 큰 경우
            r--;
        }
    }

    cout << a << ' ' << b << '\n';

    return 0;
}