#include <iostream>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int N;

void flip(string &s, int idx) {  // 전구 뒤집기
    for (int i = idx - 1; i <= idx + 1; i++) {
        if (i >= 0 && i < N) {
            if (s[i] == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> N >> s1 >> s2;

    int res = INT_MAX;

    // 첫번째 스위치 안누르는 경우
    string cur = s1;
    int cnt = 0;

    for (int i = 1; i < N; i++) {
        if (cur[i - 1] != s2[i - 1]) {
            flip(cur, i);
            cnt++;
        }
    }

    if (cur == s2) res = min(res, cnt);

    // 첫번째 스위치 누르는 경우
    cur = s1;
    cnt = 0;

    flip(cur, 0);
    cnt++;

    for (int i = 1; i < N; i++) {
        if (cur[i - 1] != s2[i - 1]) {
            flip(cur, i);
            cnt++;
        }
    }

    if (cur == s2) res = min(res, cnt);

    if (res == INT_MAX) cout << -1 << '\n';  // 불가능
    else cout << res << '\n';

    return 0;
}