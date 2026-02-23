"""
BOJ14427. 수열과 쿼리 15

[문제]
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

1 i v : Ai를 v로 바꾼다. (1 ≤ i ≤ N, 1 ≤ v ≤ 109)
2 : 수열에서 크기가 가장 작은 값의 인덱스를 출력한다. 그러한 값이 여러개인 경우에는 인덱스가 작은 것을 출력한다.
수열의 인덱스는 1부터 시작한다.

[입력]
첫째 줄에 수열의 크기 N이 주어진다. (1 ≤ N ≤ 100,000)
둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)
셋째 줄에는 쿼리의 개수 M이 주어진다. (1 ≤ M ≤ 100,000)
넷째 줄부터 M개의 줄에는 쿼리가 주어진다.

[출력]
2번 쿼리에 대해서 정답을 한 줄에 하나씩 순서대로 출력한다.
"""

from heapq import heappop, heappush

import sys
input = lambda: sys.stdin.readline().rstrip()

# main
N = int(input()) # N: 수열의 크기
sequence = list(map(int, input().split()))  # sequence: 수열 Ai

# 최소 힙: (값, 인덱스) 형태로 저장 → 값이 같으면 자동으로 인덱스가 작은 것이 먼저 나온다
heap = []

# 초기 수열을 힙에 전부 넣기
for i in range(N):
    heappush(heap, (sequence[i], i + 1))

M = int(input())    # M: 쿼리 개수

# M개의 쿼리 처리
for _ in range(M):
    query = list(map(int, input().split())) # 쿼리 입력 받기
    # 만약 쿼리가 1로 시작한다면:
    if query[0] == 1:
        # [1 i v] → 수열에서 i번째 인덱스의 원소를 v로 변경
        sequence[query[1] - 1] = query[2]
        heappush(heap, (query[2], query[1]))    # 힙에는 새 값만 추가, 기존 값은 제거하지 않음(Lazy Deletion)
    # 만약 쿼리가 2로 시작한다면:
    elif query[0] == 2:
        # [2] → 최솟값의 인덱스 출력
        while heap:
            value, idx = heap[0]    # heap의 top
            # 힙의 top이 수열의 현재 값과 일치하면, 이 값이 현재 최솟값이므로 출력 
            if sequence[idx - 1] == value:
                print(idx)
                break
            # 힙의 top이 수열의 현재 값과 일치하지 않으면, 과거에 변경되었지만 힙에 남아있던 오래된 데이터이므로 버림
            else:
                heappop(heap)