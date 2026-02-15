#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C, M;
    cin >> N >> C;
    cin >> M;

    vector<vector<pair<int, int>>> arr(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        arr[u].push_back({v, w});  // ((u, v), w) : 마을 u에서 마을 v로 w박스만큼 배송
    }

    for (int i = 1; i <= N; i++) {
        sort(arr[i].begin(), arr[i].end());  // 받는 마을 기준으로 오름차순 정렬
    }

    priority_queue<int> pq;
    vector<int> box(N + 1, 0);  // i번째 마을에 배송될 박스의 갯수
    int temp = 0, res = 0;

    for (int u = 1; u <= N; u++) {  // 1번 마을부터  순회하면서
        if (box[u] > 0) {  // 박스 내리기
            res += box[u];
            temp -= box[u];
            box[u] = 0;
        }

        for (auto [v, w] : arr[u]) {
            pq.push(v);  // 박스 싣기
            temp += w;
            box[v] += w;

            while (temp > C && !pq.empty()) {  // 트럭 용량 초과 시
                int tar = pq.top();  // 가장 먼 마을
                pq.pop();

                int remove = min(box[tar], temp - C);  // 초과된 용량
                box[tar] -= remove;  // 초과된 용량 제거
                temp -= remove;

                if (box[tar] > 0) {  // 초과량 제거하고도 해당 마을에 택배 보내면 다시 pq에 push
                    pq.push(tar);
                }
            }
        }
    }

    cout << res << '\n';

    return 0;
}