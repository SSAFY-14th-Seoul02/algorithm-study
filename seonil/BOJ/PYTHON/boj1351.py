"""
BOJ1351. 무한 수열

[문제]
무한 수열 A는 다음과 같다.

A0 = 1
Ai = A⌊i/P⌋ + A⌊i/Q⌋ (i ≥ 1)
N, P와 Q가 주어질 때, AN을 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 3개의 정수 N, P, Q가 주어진다.

[출력]
첫째 줄에 AN을 출력한다.

[제한]
0 ≤ N ≤ 10^12
2 ≤ P, Q ≤ 10^9
"""

import sys
input = lambda: sys.stdin.readline().rstrip()

# 메모이제이션을 위한 딕셔너리(보통 dp는 배열이지만... 입력이 크고(최대 10^12), 실제 방문하는 숫자는 많지 않으므로 딕셔너리 채택)
memo = {0: 1}

def solve(i):
    # 메모이제이션: 이미 계산된 값이면 바로 반환함
    if i in memo:
        return memo[i]
    
    # 점화식: 점화식: A_i = A_{floor(i/p)} + A_{floor(i/q)}
    # 딕셔너리에 계산값 저장하기
    memo[i] = solve(i//P) + solve(i//Q)
    return memo[i]

# main
N, P, Q = map(int, input().split()) # N, P, Q 정수 입력 받기
print(solve(N)) # 계산 결과 반환
