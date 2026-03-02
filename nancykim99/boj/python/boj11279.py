'''
BOJ11279 : 최대 힙 (S2)

해결 방법 :
heapq에 음수로 넣는 방법을 활용하여 해결
'''
import sys, heapq
input = sys.stdin.readline

n = int(input())
heap = []

for _ in range(n):
    i = int(input())
    if i == 0:
        if not heap:
            print(0)
            continue
        print(-heapq.heappop(heap))
    else:
        heapq.heappush(heap, -i)
