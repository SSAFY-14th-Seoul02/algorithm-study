"""
BOJ1806. 부분합

[문제]
10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다.
이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다.
둘째 줄에는 수열이 주어진다. 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.

[출력]
첫째 줄에 구하고자 하는 최소의 길이를 출력한다. 만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.
"""

import sys
input = lambda: sys.stdin.readline().rstrip()

# main

import sys
input = sys.stdin.readline

N, S = map(int, input().split())        # N: 수열 길이, S: 만들어야 하는 최소 부분합
arr = list(map(int, input().split()))   # 수열 입력 받기

left = 0                # 슬라이딩 윈도우의 왼쪽 포인터
total = 0               # 현재 윈도우의 합
answer = float('inf')   # 조건을 만족하는 최소 길이 (처음에는 무한대로 설정)

# right 포인터를 하나씩 오른쪽으로 확장하면서 윈도우 크기를 늘림
for right in range(N):

    # 새로운 원소를 윈도우에 포함 → 부분합 증가
    total += arr[right]

    # 현재 부분합이 S 이상이라면, "조건을 만족하는 구간"이므로 길이를 줄일 수 있는지 확인
    while total >= S:

        # 현재 구간 길이 계산
        # 현재 구간 길이: right - left + 1
        answer = min(answer, right - left + 1)

        # 더 짧은 구간이 가능한지 확인하기 위해, 왼쪽 원소를 제거하고 left를 오른쪽으로 이동
        total -= arr[left]
        left += 1


# 결과 출력
print(0 if answer == float('inf') else answer)