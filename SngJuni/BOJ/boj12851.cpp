#include <iostream>
#include <queue>

using namespace std;

int N, K;
int res[100001];        // 각 위치까지 최소 시간
long long cnt[100001];  // 각 위치까지 최단시간으로 가는 방법 수

void bfs(int start) {
    queue<int> q;
    q.push(start);
    res[start] = 1;
    cnt[start] = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int next[3] = {cur - 1, cur + 1, cur * 2};

        for (int i = 0; i < 3; i++) {
            int nx = next[i];
            
            if (nx < 0 || nx > 100000) continue;

            if (res[nx] == 0) {  // 아직 방문 안 했으면 최초 방문
                res[nx] = res[cur] + 1;
                cnt[nx] = cnt[cur];
                q.push(nx);
            }
            else if (res[nx] == res[cur] + 1) {  // 이미 방문했지만 같은 최단시간
                cnt[nx] += cnt[cur];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    bfs(N);

    cout << res[K] - 1 << '\n';  // 시간 (처음에 +1 했으니 -1)
    cout << cnt[K] << '\n';

    return 0;
}
