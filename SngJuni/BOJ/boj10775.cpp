#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int G, P;
vector<int> parent;

// Union-Find: x가 속한 집합의 루트 찾기
int find(int x) {
    if (parent[x] == x) return x;

    return parent[x] = find(parent[x]);  // 경로 압축
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> G >> P;

    parent.assign(G + 1, 0);
    iota(parent.begin(), parent.end(), 0);  // parent[i] = i 로 초기화

    int res = 0;

    for (int i = 0; i < P; i++) {
        int g;
        cin >> g;

        int root = find(g);    // g 이하에서 사용 가능한 가장 큰 게이트 찾기
        if (root == 0) break;  // 더 이상 배정할 게이트가 없음

        res++;  // 도킹 성공
        parent[root] = find(root - 1);  // root 게이트 사용 처리 → 왼쪽 게이트와 연결
    }

    cout << res << '\n';

    return 0;
}

// 시간 초과
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int G, P;
//     cin >> G >> P;

//     vector<int> arr(G + 1, 0);

//     int res = 0;

//     for (int i = 0; i < P; i++) {
//         int g;
//         cin >> g;

//         int pos = -1;
//         for (int j = g; j >= 1; j--) {
//             if (!arr[j]) {
//                 pos = j;
//                 break;
//             }
//         }

//         if (pos == -1) break;

//         arr[pos] = 1;
//         res++;
//     }

//     cout << res << '\n';

//     return 0;
// }
