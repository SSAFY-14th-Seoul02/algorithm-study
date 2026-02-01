# BOJ5972: 택배 배송
from collections import defaultdict
from heapq import heappop, heappush
import sys
input = sys.stdin.readline

N, M = map(int, input().split())

graph = defaultdict(list)
INF = float('INF')
dist = [INF] * (N + 1)

for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append((c, b))
    graph[b].append((c, a))

pq = []
heappush(pq, (0, 1))
dist[1] = 0

while pq:
    c_cost, node = heappop(pq)
    for (n_cost, n_node) in graph[node]:
        t_cost = c_cost + n_cost

        if t_cost >= dist[n_node]:
            continue

        dist[n_node] = t_cost
        heappush(pq, (t_cost, n_node))

print(dist[N])