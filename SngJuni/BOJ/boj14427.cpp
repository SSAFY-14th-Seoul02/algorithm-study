#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
vector<int> arr;
vector<pair<int, int>> seg;

// 트리 만들기 (min 사용해서 최솟값을 노드에 저장)
pair<int, int> build(int node, int s, int e) {
    if (s == e) return seg[node] = {arr[s], s};
    
    int mid = (s + e) / 2;
    return seg[node] = min(build(node * 2, s, mid), build(node * 2 + 1, mid + 1, e));
}

// 값 변경
void update(int node, int s, int e, int idx, int val) {
    if (idx < s || e < idx) return;

    if (s == e) {
        seg[node] = {val, idx};
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, val);
    update(node * 2 + 1, mid + 1, e, idx, val);
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}

// 최솟값 반환
pair<int, int> query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return {INT_MAX, INT_MAX};
    if (l <= s && e <= r) return seg[node];

    int mid = (s + e) / 2;
    return min(query(node * 2, s, mid, l, r), query(node * 2 + 1, mid + 1, e, l, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    
    arr.assign(N + 1, 0);
    seg.assign(4 * N, {0, 0});

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    build(1, 1, N);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int cmd;
        int a, b;

        cin >> cmd;

        if (cmd == 1) {  // 값 변경
            cin >> a >> b;
            update(1, 1, N, a, b);
        } else if (cmd == 2) {  // 최솟값 출력
            cout << query(1, 1, N, 1, N).second << '\n';
        }
    }

    return 0;
}