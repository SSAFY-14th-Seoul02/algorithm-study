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
    arr.assign(N, {0, 0});

    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second; // 시작, 종료
    }

    sort(arr.begin(), arr.end()); // 시작 시간 기준 정렬

    // 각 회의실의 종료 시간을 저장하는 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto [s, e] : arr) {
        // 가장 빨리 끝나는 회의실 재사용 가능하면 pop
        if (!pq.empty() && pq.top() <= s) {
            pq.pop();
        }
        pq.push(e); // 현재 회의 종료 시간 추가
    }

    cout << pq.size() << '\n'; // 필요한 회의실 수
    
    return 0;
}
