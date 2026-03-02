#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<pair<int, int>> req;
        for (int i = 0; i < M; i++) {  // (끝 번호, 시작 번호) 로 저장
            int a, b;
            cin >> a >> b;
            req.push_back({b, a});
        }

        sort(req.begin(), req.end());  // 끝 번호 기준으로 오름차순 정렬

        vector<bool> used(N + 1, false);
        int res = 0;

        for (auto [b, a] : req) {
            // [a, b] 범위 내에서 배정 가능한 가장 작은 책 찾기
            for (auto book = a; book <= b; book++) {
                if (!used[book]) {
                    used[book] = true;  // 해당 책 사용처리
                    res++;
                    break;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}