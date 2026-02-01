#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> arr;
    arr.assign(0, 0);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        int l = 0, r = arr.size();

        // 이분 탐색
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr[mid] >= x) r = mid;  // x 이상이 처음 나오는 위치
            else l = mid + 1;            // x보다 작으면 오른쪽 탐색
        }

        if (l == arr.size()) arr.push_back(x); // 가장 뒤에 붙이면 길이 증가
        else arr[l] = x;                       // 더 작은 값으로 끝값 갱신
    }

    cout << arr.size() << '\n';

    return 0;
}
