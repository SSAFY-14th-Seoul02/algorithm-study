# BOJ1916: 최소비용 구하기
from heapq import heappop, heappush
import sys
input = sys.stdin.readline

N, M = int(input()), int(input())  # N: 도시 수 / M: 간선 수

arrow = [[] for _ in range(N + 1)]  # 버스의 출발-(도착지, 비용)
for _ in range(M):
    a, b, cost = map(int, input().split())
    arrow[a].append((cost, b))

start, end = map(int, input().split())  # 문제의 출발지와 도착지

INF = float('inf')
memo_min = [INF] * (N + 1)

pq = []
heappush(pq, (0, start))
memo_min[start] = 0

while pq:
    cost, c_node = heappop(pq)

    if memo_min[c_node] < cost:
        continue

    if c_node == end:
        break

    for n_cost, n_node in arrow[c_node]:
        t_cost = cost + n_cost

        if t_cost < memo_min[n_node]:
            memo_min[n_node] = t_cost
            heappush(pq, (t_cost, n_node))

print(memo_min[end])
