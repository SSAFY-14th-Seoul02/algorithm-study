'''
BOJ11286 : 절댓값 힙 (S1)

해결 방법 :
절댓값과 원래값을 튜플로 넣어 출력 시, 원래값을 구할 수 있게 함
heapq로 가장 작은 절댓값 구함
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
        j, k = heapq.heappop(heap)
        print(k)
    else:
        heapq.heappush(heap, (abs(i), i))