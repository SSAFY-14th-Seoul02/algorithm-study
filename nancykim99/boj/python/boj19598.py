'''
BOJ19598 : 최소 회의실 개수 (G5)

해결 방법 : 
시작 시간으로 sort 한 후, 다음 회의 시간의 시작시간과 앞 회의 시간의 끝시간을 비교하여 우선순위큐로 해결
'''
import sys
import heapq
input = sys.stdin.readline

n = int(input())
arr = []

for _ in range(n):
    a, b = map(int, input().split())
    arr.append((a, b))

arr.sort()

heap = []
cnt = 1
heapq.heappush(heap, arr[0][1])

for i in range(1, n):
    if arr[i][0] >= heap[0]:
        heapq.heappop(heap)
    else:
        cnt += 1
    heapq.heappush(heap, arr[i][1])

print(cnt)