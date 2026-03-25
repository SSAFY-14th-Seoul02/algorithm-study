#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long res = 0;
    int left = 0;
    vector<bool> visited(100001, false);

    for (int right = 0; right < N; right++) {
        // 중복 원소가 나오면 왼쪽 포인터를 이동
        while (visited[arr[right]]) {
            visited[arr[left]] = false;
            left++;
        }
        visited[arr[right]] = true;

        // 현재 [left, right] 구간은 모두 고유한 원소로 구성됨
        // 이 구간을 만들 수 있는 시작점은 left부터 right까지 총 (right - left + 1)개
        res += (right - left + 1);
    }

    cout << res << '\n';

    return 0;
}