#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// target 이상이 처음 등장하는 위치
int lowerBound(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

// target 초과가 처음 등장하는 위치
int upperBound(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    int m, n;
    cin >> m >> n;

    vector<int> A(m);
    vector<int> B(n);

    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    vector<int> sumA;
    vector<int> sumB;

    // 아무 것도 선택하지 않는 경우
    sumA.push_back(0);
    sumB.push_back(0);

    // A의 원형 부분합 생성 (길이 1 ~ m-1)
    for (int i = 0; i < m; i++) {
        int cur = 0;

        for (int len = 0; len < m - 1; len++) {
            cur += A[(i + len) % m];
            sumA.push_back(cur);
        }
    }

    // A 전체 피자 선택
    int totalA = 0;
    for (int v : A) {
        totalA += v;
    }
    sumA.push_back(totalA);

    // B의 원형 부분합 생성 (길이 1 ~ n-1)
    for (int i = 0; i < n; i++) {
        int cur = 0;

        for (int len = 0; len < n - 1; len++) {
            cur += B[(i + len) % n];
            sumB.push_back(cur);
        }
    }

    // B 전체 피자 선택
    int totalB = 0;
    for (int v : B) {
        totalB += v;
    }
    sumB.push_back(totalB);

    // B 부분합 정렬 (이분 탐색 위해)
    sort(sumB.begin(), sumB.end());

    long long res = 0;

    for (int sA : sumA) {
        int target = x - sA;

        // B에서 target이 되는 부분합 개수 계산
        res += upperBound(sumB, target) - lowerBound(sumB, target);
    }

    cout << res << '\n';

    return 0;
}