#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, x, P, L;
    string cmd;

    cin >> N;

    vector<int> arr(100001, -1);  // 문제 번호별 난이도 (-1이면 추천 문제 리스트에 존재 X)

    priority_queue<pair<int, int>> pq;  // 최대 힙
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rpq;  // 최소 힙

    for (int i = 0; i < N; i++) {
        cin >> P >> L;

        arr[P] = L;
        pq.push({L, P});
        rpq.push({L, P});
    }

    cin >> M;

    while (M--) {
        cin >> cmd;

        if (cmd == "recommend") {
            cin >> x;

            if (x == 1) {
                while (!pq.empty()) {  // 가장 어려운 문제 번호
                    auto [l, p] = pq.top();

                    if (arr[p] == l) break;
                    pq.pop();
                }
                cout << pq.top().second << '\n';
            } else if (x == -1) {  // 가장 쉬운 문제 번호
                while (!rpq.empty()) {
                    auto [l, p] = rpq.top();

                    if (arr[p] == l) break;
                    rpq.pop();
                }
                cout << rpq.top().second << '\n';
            }
        } else if (cmd == "add") {  // 문제 추가
            cin >> P >> L;

            arr[P] = L;
            pq.push({L, P});
            rpq.push({L, P});
        } else if (cmd == "solved") {  // 문제 제거
            cin >> P;

            arr[P] = -1;
        }
    }

    return 0;
}