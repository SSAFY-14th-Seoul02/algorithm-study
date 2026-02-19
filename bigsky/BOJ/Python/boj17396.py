# BOJ17396: 백도어
from heapq import heappush, heappop
import sys

input = sys.stdin.readline
INF = float('inf')

N, M = map(int, input().split())
is_visible = list(map(int, input().split()))

graph = [[] for _ in range(N)]
for _ in range(M):
    u, v, t = map(int, input().split())
    graph[u].append((v, t))
    graph[v].append((u, t))

is_visible[N-1] = 0

distances = [INF] * N
distances[0] = 0
pq = [(0, 0)]

while pq:
    c_cost, c_node = heappop(pq)

    if distances[c_node] < c_cost:
        continue

    for n_node, w in graph[c_node]:
        if is_visible[n_node]:
            continue

        n_cost = c_cost + w

        if n_cost < distances[n_node]:
            distances[n_node] = n_cost
            heappush(pq, (n_cost, n_node))

if distances[N-1] == INF:
    print(-1)
else:
    print(distances[N-1])
