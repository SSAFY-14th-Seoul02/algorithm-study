#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
vector<vector<int>> a;

void op1() { // 상하 반전
    int n = (int)a.size(), m = (int)a[0].size();
    for (int i = 0; i < n / 2; i++) {
        swap(a[i], a[n - 1 - i]);
    }
}

void op2() { // 좌우 반전
    int n = (int)a.size(), m = (int)a[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            swap(a[i][j], a[i][m - 1 - j]);
        }
    }
}

void op3() { // 오른쪽 90도 회전
    int n = (int)a.size(), m = (int)a[0].size();
    vector<vector<int>> b;
    b.assign(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][n - 1 - i] = a[i][j];
        }
    }
    a = b;
}

void op4() { // 왼쪽 90도 회전
    int n = (int)a.size(), m = (int)a[0].size();
    vector<vector<int>> b;
    b.assign(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[m - 1 - j][i] = a[i][j];
        }
    }
    a = b;
}

void op5() { // 사분면 시계 방향 이동
    int n = (int)a.size(), m = (int)a[0].size();
    int hn = n / 2, hm = m / 2;

    vector<vector<int>> b;
    b.assign(n, vector<int>(m, 0));

    // 1 -> 2
    for (int i = 0; i < hn; i++)
        for (int j = 0; j < hm; j++)
            b[i][j + hm] = a[i][j];

    // 2 -> 3
    for (int i = 0; i < hn; i++)
        for (int j = hm; j < m; j++)
            b[i + hn][j] = a[i][j];

    // 3 -> 4
    for (int i = hn; i < n; i++)
        for (int j = hm; j < m; j++)
            b[i][j - hm] = a[i][j];

    // 4 -> 1
    for (int i = hn; i < n; i++)
        for (int j = 0; j < hm; j++)
            b[i - hn][j] = a[i][j];

    a = b;
}

void op6() { // 사분면 반시계 방향 이동
    int n = (int)a.size(), m = (int)a[0].size();
    int hn = n / 2, hm = m / 2;

    vector<vector<int>> b;
    b.assign(n, vector<int>(m, 0));

    // 1 -> 4
    for (int i = 0; i < hn; i++)
        for (int j = 0; j < hm; j++)
            b[i + hn][j] = a[i][j];

    // 4 -> 3
    for (int i = hn; i < n; i++)
        for (int j = 0; j < hm; j++)
            b[i][j + hm] = a[i][j];

    // 3 -> 2
    for (int i = hn; i < n; i++)
        for (int j = hm; j < m; j++)
            b[i - hn][j] = a[i][j];

    // 2 -> 1
    for (int i = 0; i < hn; i++)
        for (int j = hm; j < m; j++)
            b[i][j - hm] = a[i][j];

    a = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> R;

    a.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        int op;
        cin >> op;

        if (op == 1) op1();
        else if (op == 2) op2();
        else if (op == 3) op3();
        else if (op == 4) op4();
        else if (op == 5) op5();
        else op6();
    }

    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << (j + 1 == m ? '\n' : ' ');
        }
    }

    return 0;
}
