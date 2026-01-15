/*
BOJ9465 : 스티커 (S1)

해결 방법 : 각 칸마다 위면 아래의 n-1, n-2 중 max를 구하기. 그리고 마지막 열의 최댓값 구하기
1. 0일 경우, 그대로 그 칸 저장
2. 1일 경우, 위면, 아래. 아래면 위
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<vector<int>> sticker(2, vector<int>(m));
        for (int j = 0; j < m; j++) {
            cin >> sticker[0][j];
        }
        for (int j = 0; j < m; j++) {
            cin >> sticker[1][j];
        }
        vector<vector<int>> sum_num(2, vector<int>(m));
        for (int j = 0; j < m; j++) {
            if (j == 0) {
                sum_num[0][j] = sticker[0][j];
                sum_num[1][j] = sticker[1][j];
            } else if (j == 1) {
                sum_num[0][j] = sticker[0][j] + sum_num[1][j-1];
                sum_num[1][j] = sticker[1][j] + sum_num[0][j-1];
            } else {
                sum_num[0][j] = sticker[0][j] + max(sum_num[1][j-1], sum_num[1][j-2]);
                sum_num[1][j] = sticker[1][j] + max(sum_num[0][j-1], sum_num[0][j-2]);
            }
        }
        cout << max(sum_num[0][m-1], sum_num[1][m-1]) << '\n';
    }
    return 0;
}