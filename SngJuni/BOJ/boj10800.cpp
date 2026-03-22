#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, pair<int, int>>> ball(N);  // (size, (color, index))
    for (int i = 0; i < N; i++) {
        cin >> ball[i].second.first >> ball[i].first;
        ball[i].second.second = i;
    }

    sort(ball.begin(), ball.end());  // 크기 순으로 정렬

    vector<int> res(N);
    vector<int> color_sum(N + 1, 0);  // 같은 색인 공의 합

    int total = 0;  // 현재까지의 공의 합
    int j = 0;

    for (int i = 0; i < N; i++) {
        while (j < N && ball[j].first < ball[i].first) {
            total += ball[j].first;  // 현재 공보다 작은 공들의 합
            color_sum[ball[j].second.first] += ball[j].first;  // 현재 공보다 작은 공들의 색깔별 합
            j++;
        }
        res[ball[i].second.second] = total - color_sum[ball[i].second.first];  // 현재 공보다 작은 공들의 합 - 현재 공보다 작은 공들의 색깔별 합
    }

    for (int i = 0; i < N; i++) {
        cout << res[i] << "\n";
    }

    return 0;
}