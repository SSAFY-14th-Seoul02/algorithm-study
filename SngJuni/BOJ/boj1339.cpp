#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> alpha(26, 0);

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        int M = s.size();
        int temp = 1;

        for (int j = M - 1; j >= 0; j--) {  // 각 알파벳의 자릿수 치환해서 저장
            alpha[s[j] - 'A'] += temp;
            temp *= 10;
        }
    }

    sort(alpha.rbegin(), alpha.rend());  // 내림차순 정렬

    int res = 0;
    int num = 9;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] == 0) {  // 모든 알파벳 사용
            break;
        } else {
            res += num * alpha[i];  // 9부터 사용해서 최댓값 만들기
            num--;
        }
    }

    cout << res << '\n';
    
    return 0;
}