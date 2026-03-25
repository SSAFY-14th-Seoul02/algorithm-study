#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;
vector<int> res;
vector<bool> visited;

void dfs(int start, int cur) {
    if (!visited[cur]) {
        visited[cur] = true;
        dfs(start, arr[cur]);
    } else {
        // 이미 방문한 노드에 도달 → 사이클 or 이미 탐색된 경로
        if (cur == start) {
            res.push_back(start);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    arr.assign(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        visited.assign(N + 1, false);  // 시작점마다 방문 배열 초기화
        dfs(i, i);  // i에서 출발해서 i로 돌아오는지 확인
    }

    sort(res.begin(), res.end());

    cout << res.size() << '\n';

    for (int x : res) {
        cout << x << '\n';
    }

    return 0;
}