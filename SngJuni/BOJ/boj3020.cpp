#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, H;
    cin >> N >> H;

    vector<int> cave(H + 2, 0);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (!(i % 2)) {  // 홀
            cave[1]++;      // 석순 시작
            cave[x + 1]--;  // 석순 끝
        } else {         // 짝
            cave[H - x + 1]++;  // 종유석 시작
            cave[H + 1]--;      // 종유석 끝
        }
    }

    int cur = 0;
    int min_res = INT_MAX;
    int min_cnt = 0;

    for (int i = 1; i <= H; i++) {
        cur += cave[i];  // 해당 높이의 장애물 수
        if (min_res > cur) {  // 최솟값 갱신
            min_res = cur;
            min_cnt = 1;
        } else if (min_res == cur) {
            min_cnt++;
        }
    }
 
    cout << min_res << ' ' << min_cnt << '\n';

    return 0;
}


// 시간 초과
// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N, H;
//     cin >> N >> H;

//     vector<int> arr(N, 0);
//     for (int i = 0; i < N; i++) {
//         cin >> arr[i];
//     }

//     vector<int> cave(H, 0);
//     for (int i = 0; i < N; i++) {
//         int temp = arr[i];
//         if (!(i % 2)) {
//             for (int j = H - 1; j >= 0; j--) {
//                 if (temp > 0) {
//                     cave[j]++;
//                     temp--;
//                 }
//             }
//         } else {
//             for (int j = 0; j < H; j++) {
//                 if (temp > 0) {
//                     cave[j]++;
//                     temp--;
//                 }
//             }
//         }
//     }

//     int min_res = INT_MAX;
//     int min_cnt = 0;
//     for (int i = 0; i < H; i++) {
//         if (min_res > cave[i]) {
//             min_res = cave[i];
//             min_cnt = 1;
//         } else if (min_res == cave[i]) {
//             min_cnt++;
//         }
//     }

//     cout << min_res << ' ' << min_cnt << '\n';

//     return 0;
// }


// 메모리 초과 - 2차원 배열 때문인듯
// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N, H;
//     cin >> N >> H;

//     vector<int> arr(N, 0);
//     for (int i = 0; i < N; i++) {
//         cin >> arr[i];
//     }

//     vector<vector<int>> space(H, vector<int>(N, 0));

//     for (int i = 0; i < N; i++) {
//         int temp = arr[i];

//         if (!(i % 2)) {  // 홀 (동굴 기준, idx X)
//             for (int j = H - 1; j >= 0; j--) {
//                 if (i != 0) {
//                     space[j][i] = space[j][i - 1];
//                 }

//                 if (temp > 0) {
//                     space[j][i]++;
//                     temp--;
//                 }
//             }
//         } else {         // 짝
//             for (int j = 0; j < H ; j++) {
//                 space[j][i] = space[j][i - 1];

//                 if (temp > 0) {
//                     space[j][i]++;
//                     temp--;
//                 }
//             }
//         }
//     }

//     int min_res = INT_MAX;
//     int min_cnt = 0;

//     for (int i = 0; i < H; i++) {
//         if (min_res > space[i][N - 1]) {
//             min_res = space[i][N - 1];
//             min_cnt = 1;
//         } else if (min_res == space[i][N - 1]) {
//             min_cnt++;
//         }
//     }

//     cout << min_res << ' ' << min_cnt << '\n';

//     return 0;
// }