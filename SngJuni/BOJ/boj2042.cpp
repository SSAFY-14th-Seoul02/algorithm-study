#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<long long> arr;  // 원본 수열
vector<long long> seg;  // 세그먼트 트리

// 1) 트리 만들기
long long build(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s];  // 리프 == 원소 1개

    int mid = (s + e) / 2;
    return seg[node] = build(node * 2, s, mid) + build(node * 2 + 1, mid + 1, e);
}

// 2) 수 변경
void update(int node, int s, int e, int idx, long long val) {
    if (idx < s || e < idx) return;  // 구간 내에 존재하는 idx가 아니면 무시

    if (s == e) {  // 리프면 실제 값 변경
        seg[node] = val;
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, val);
    update(node * 2 + 1, mid + 1, e, idx, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];  // 자식들의 합 변경
}

// 3) 구간 합 구하기
long long query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;  // 구간의 바깥
    if (l <= s && e <= r) return seg[node];  // 구간에 완전 포함 -> 바로 사용

    int mid = (s + e) / 2;  // 일부만 겹침 -> 자식으로 내려가서 처리
    return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    arr.assign(N + 1, 0);
    seg.assign(4 * N, 0);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    build(1, 1, N);

    for (int i = 0; i < M + K; i++) {
        int a;
        long long b, c;

        cin >> a >> b >> c;

        if (a == 1) {
            update(1, 1, N, b, c);  // b번째 수를 c로
        } else {
            cout << query(1, 1, N, b, c) << '\n';  // b부터 c까지 구간합 출력
        }
    }

    return 0;
}