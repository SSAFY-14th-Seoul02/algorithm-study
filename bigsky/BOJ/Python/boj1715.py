# BOJ1715: 카드 정렬하기
import sys
from heapq import heappush, heappop
input = sys.stdin.readline

N = int(input())
pq = []
for _ in range(N):
    cards = int(input())
    heappush(pq, cards)

total = 0

while len(pq) != 1:
    sm = heappop(pq) + heappop(pq)
    total += sm
    heappush(pq, sm)

print(total)