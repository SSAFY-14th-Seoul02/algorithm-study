"""
# [Bronze I] 부녀회장이 될테야 - 2775

[문제 링크](https://www.acmicpc.net/problem/2775)

### 성능 요약

메모리: 109544 KB, 시간: 96 ms

### 분류

수학, 구현, 다이나믹 프로그래밍

### 제출 일자

2026년 2월 27일 16:30:27

### 문제 설명

<p>평소 반상회에 참석하는 것을 좋아하는 주희는 이번 기회에 부녀회장이 되고 싶어 각 층의 사람들을 불러 모아 반상회를 주최하려고 한다.</p>

<p>이 아파트에 거주를 하려면 조건이 있는데, “a층의 b호에 살려면 자신의 아래(a-1)층의 1호부터 b호까지 사람들의 수의 합만큼 사람들을 데려와 살아야 한다” 는 계약 조항을 꼭 지키고 들어와야 한다.</p>

<p>아파트에 비어있는 집은 없고 모든 거주민들이 이 계약 조건을 지키고 왔다고 가정했을 때, 주어지는 양의 정수 k와 n에 대해 k층에 n호에는 몇 명이 살고 있는지 출력하라. 단, 아파트에는 0층부터 있고 각층에는 1호부터 있으며, 0층의 i호에는 i명이 산다.</p>

### 입력

 <p>첫 번째 줄에 Test case의 수 T가 주어진다. 그리고 각각의 케이스마다 입력으로 첫 번째 줄에 정수 k, 두 번째 줄에 정수 n이 주어진다</p>

### 출력

 <p>각각의 Test case에 대해서 해당 집에 거주민 수를 출력하라.</p>


"""

import sys
input = lambda: sys.stdin.readline().rstrip()

T = int(input())

for _ in range(T):
    k = int(input()) # k는 층,
    n = int(input()) # n은 호
    dp = [[0] * (n + 1) for _ in range(k + 1)]
    for k_idx in range(k + 1):
        for n_idx in range(1, n + 1):
            if k_idx == 0:
                dp[0][n_idx] = n_idx
            else:
                dp[k_idx][n_idx] = dp[k_idx][n_idx - 1] + dp[k_idx - 1][n_idx]
    print(dp[k][n])