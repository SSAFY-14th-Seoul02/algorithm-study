#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
vector<int> arr;
vector<pair<int,int>> seg;

// 노드 합치기
pair<int,int> mergeNode(const pair<int,int>& a, const pair<int,int>& b) {
    return { min(a.first, b.first), max(a.second, b.second) };
}


// 세그먼트 트리 만들기
pair<int,int> build(int node, int s, int e) {
    if (s == e) return seg[node] = {arr[s], arr[s]};

    int mid = (s + e) / 2;

    return seg[node] = mergeNode(build(node * 2, s, mid), build(node * 2 + 1, mid + 1, e));
}

// l, r 구간 내 최소/최대 구하기
pair<int,int> query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return {INT_MAX, INT_MIN};
    if (l <= s && e <= r) return seg[node];

    int mid = (s + e) / 2;

    return mergeNode(query(node * 2, s, mid, l, r), query(node * 2 + 1, mid + 1, e, l, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    arr.assign(N + 1, 0);
    seg.assign(4 * N, {INT_MAX, INT_MIN});

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    build(1, 1, N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        cout << query(1, 1, N, a, b).first << ' ' << query(1, 1, N, a, b).second << '\n';
    }

    return 0;
}