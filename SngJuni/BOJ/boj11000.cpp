#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int,int>> arr;
    arr.assign(N, {});

    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    // 시작 시간 기준 정렬
    sort(arr.begin(), arr.end());

    // 각 강의실의 종료 시간을 관리하는 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto [s, e] : arr) {
        if (!pq.empty() && pq.top() <= s) {
            pq.pop();
        }
        pq.push(e);
    }

    cout << pq.size() << '\n';

    return 0;
}
