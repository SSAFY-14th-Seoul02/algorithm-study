#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    // dp[i] = N을 i번 써서 만들 수 있는 모든 숫자 집합
    vector<set<int>> dp(9);

    // N을 1번 ~ 8번까지 사용하는 경우를 모두 시도
    for (int i = 1; i <= 8; i++) {

        // (1) NN, NNN 같은 "이어붙인 숫자" 만들기
        int num = 0;
        for (int j = 0; j < i; j++) {
            num = num * 10 + N;  // ex) 5 -> 55 -> 555
        }
        dp[i].insert(num); // 해당 숫자 넣기

        // (2) i개를 두 그룹으로 나눠서 조합
        for (int j = 1; j < i; j++) {

            // dp[j]에서 하나 꺼내고
            for (int a : dp[j]) {

                // dp[i-j]에서 하나 꺼내서
                for (int b : dp[i - j]) {

                    // 사칙연산 결과를 dp[i]에 추가
                    dp[i].insert(a + b);  // 덧셈
                    dp[i].insert(a - b);  // 뺄셈
                    dp[i].insert(a * b);  // 곱셈

                    // 나눗셈은 0으로 나누는 것 방지
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }

        // (3) 목표 숫자가 만들어졌는지 확인
        if (dp[i].count(number)) return i;
    }

    // 8번까지 써도 못 만들면 -1
    return -1;
}