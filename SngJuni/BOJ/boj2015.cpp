#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    // cnt[x] : 지금까지 등장한 누적합이 x 였던 횟수
    unordered_map<long long, long long> cnt;

    long long acc = 0;  // 현재까지 누적합
    long long res = 0;  // 합이 K인 부분합의 갯수

    cnt[0] = 1;

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;

        acc += x;

        // 현재 누적합 acc에서 K를 빼면, 과거에 그 값이 몇 번 나왔는지가
        // 곧 현재 위치에서 끝나는 합 K인 부분 배열의 개수
        res += cnt[acc - K];
        cnt[acc]++;
    }

    cout << res << '\n';  // 결과 출력

    return 0;
}

// ------- 단순 이중 for문 -> 시간 초과 -------
// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N, K, res = 0;
//     cin >> N >> K;

//     vector<int> psum(N + 1);
//     for (int i = 1; i <= N; i++) {
//         int x;
//         cin >> x;
//         psum[i] = psum[i - 1] + x;
//     }

//     for (int i = 0; i < N; i++) {
//         for (int j = i + 1; j < N + 1; j++) {
//             if (psum[j] - psum[i] == K) res++;
//         }
//     }

//     cout << res << '\n';

//     return 0;
// }
