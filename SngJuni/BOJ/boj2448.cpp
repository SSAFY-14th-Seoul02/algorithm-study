#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<string> star;

// (y, x)를 꼭짓점으로 하고 높이가 n인 삼각형을 그린다
void draw(int y, int x, int n) {
    // 재귀의 최소 단위: 높이 3짜리 삼각형
    if (n == 3) {
        star[y][x] = '*';                               // 꼭짓점
        star[y + 1][x - 1] = star[y + 1][x + 1] = '*';  // 가운데 줄
        for (int i = -2; i <= 2; i++) {                 // 바닥 줄 (*****)
            star[y + 2][x + i] = '*';
        }
        return;
    }

    int half = n / 2;

    // 위쪽에 작은 삼각형 하나
    draw(y, x, half);
    // 왼쪽 아래에 작은 삼각형 하나
    draw(y + half, x - half, half);
    // 오른쪽 아래에 작은 삼각형 하나
    draw(y + half, x + half, half);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    // 공백으로 채운 캔버스 초기화
    // 가로 길이는 삼각형 특성상 2 * N - 1
    star.assign(N, string(2 * N - 1, ' '));

    // 전체 삼각형의 꼭짓점은 (0, N - 1)
    draw(0, N - 1, N);

    // 결과 출력
    for (int i = 0; i < N; i++) {
        cout << star[i] << '\n';
    }

    return 0;
}
