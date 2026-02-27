#include <iostream>

using namespace std;

long long countOne(long long x) {
    if (x < 0) return 0;

    long long cnt = 0;

    for (int i = 0; i <= 60; i++) {
        long long bit = 1LL << i;    // 현재 비트 값
        long long cycle = bit << 1;  // 한 주기 길이 : 2^(i + 1)
        long long total = x + 1;     // 0 ~ x 까지 총 갯수

        long long fullCycle = total / cycle;  // 완전히 들어가는 주기 갯수
        long long remain = total % cycle;     // 마지막에 남는 조각

        cnt += fullCycle * bit;  // 완전히 들어간 주기의 1의 갯수

        if (remain > bit) {  // 남은 조각에서 추가되는 1의 갯수
            cnt += (remain - bit);
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    cin >> A >> B;

    cout << countOne(B) - countOne(A - 1) << '\n';

    return 0;
}