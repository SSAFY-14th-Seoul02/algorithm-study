#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    if (a > b)
      swap(a, b);
    arr.push_back({b, a}); // {end, start}
  }

  sort(arr.begin(), arr.end()); // end 기준 오름차순 정렬

  int d;
  cin >> d;

  priority_queue<int, vector<int>, greater<int>>
      pq; // 현재 철로 안에 포함될 수 있는 선분들의 start를 저장하는 최소 힙

  int res = 0;
  for (auto &s : arr) {
    int en = s.first;  // 현재 선분의 끝점
    int st = s.second; // 현재 선분의 시작점

    if (en - st > d)
      continue;

    pq.push(st);

    // 철로 범위 왼쪽(en - d) 밖에 있는 선분 제거
    while (!pq.empty() && pq.top() < en - d) {
      pq.pop();
    }

    // 포함 가능한 선분 개수
    res = max(res, (int)pq.size());
  }

  cout << res << '\n';

  return 0;
}