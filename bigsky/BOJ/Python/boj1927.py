# BOJ1927: 최소 힙
from heapq import heappop, heappush
import sys

input = sys.stdin.readline

N = int(input())
min_heap = []

for _ in range(N):
    x = int(input())
    
    if x == 0:                            # 0이 입력되었을 때,
        if len(min_heap) == 0:       # 힙이 비어있다면 0출력
            print(0)
            continue

        print(heappop(min_heap))   # 그 외에는 가장 작은 값을 출력하고 힙에서 제거
        continue

    heappush(min_heap, x)
