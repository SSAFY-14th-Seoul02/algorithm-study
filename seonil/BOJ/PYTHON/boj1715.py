"""
BOJ1715. 카드 정렬

[문제]
정렬된 두 묶음의 숫자 카드가 있다고 하자. 각 묶음의 카드의 수를 A, B라 하면 보통 두 묶음을 합쳐서 하나로 만드는 데에는 A+B 번의 비교를 해야 한다. 이를테면, 20장의 숫자 카드 묶음과 30장의 숫자 카드 묶음을 합치려면 50번의 비교가 필요하다.
매우 많은 숫자 카드 묶음이 책상 위에 놓여 있다. 이들을 두 묶음씩 골라 서로 합쳐나간다면, 고르는 순서에 따라서 비교 횟수가 매우 달라진다. 예를 들어 10장, 20장, 40장의 묶음이 있다면 10장과 20장을 합친 뒤, 합친 30장 묶음과 40장을 합친다면 (10 + 20) + (30 + 40) = 100번의 비교가 필요하다. 그러나 10장과 40장을 합친 뒤, 합친 50장 묶음과 20장을 합친다면 (10 + 40) + (50 + 20) = 120 번의 비교가 필요하므로 덜 효율적인 방법이다.
N개의 숫자 카드 묶음의 각각의 크기가 주어질 때, 최소한 몇 번의 비교가 필요한지를 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100,000)
이어서 N개의 줄에 걸쳐 숫자 카드 묶음의 각각의 크기가 주어진다. 숫자 카드 묶음의 크기는 1,000보다 작거나 같은 양의 정수이다.

[출력]
첫째 줄에 최소 비교 횟수를 출력한다.
"""

from heapq import heappop, heappush, heapify

import sys
input = lambda: sys.stdin.readline().rstrip()

# 최소 힙을 이용해 카드 묶음을 합치는 데 최소 비교 횟수를 구하는 함수
def find_min_comparisons(bundles):

    # 리스트를 최소 힙 구조로 변환 → 매번 가장 작은 두 묶음을 선택하기 위해 필요
    heapify(bundles)

    total_comparisons = 0   # 전체 비교 횟수 누적 변수

    # 카드 묶음이 하나만 남을 때까지 반복
    while len(bundles) > 1:
        # 가장 작은 두 묶음 a, b를 꺼냄 (그리디 전략: 항상 가장 작은 것끼리 먼저 합쳐야 전체 비용 최소)
        a = heappop(bundles)
        b = heappop(bundles)
        # 두 묶음을 합치는 데 필요한 비교 횟수는 a + b
        s = a + b
        # 이번 합치기에서 발생한 비교 횟수 누적
        total_comparisons += s
        # 합쳐진 묶음을 다시 힙에 넣기
        heappush(bundles, s)
    # 모든 묶음을 하나로 만들 때까지의 최소 비교 횟수 반환
    return total_comparisons

# main
N = int(input())    # N: 숫자 카드 묶음의 개수

# 코드 묶음 입력 받기
bundles = []
for _ in range(N):
    bundle = int(input())
    bundles.append(bundle)

# 최소 비교 횟수 계산
min_comparisons = find_min_comparisons(bundles)

# 결과 출력
print(min_comparisons)