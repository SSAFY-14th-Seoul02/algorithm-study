# BOJ14938: 서강그라운드
import sys
from heapq import heappop, heappush, heapify

input = sys.stdin.readline

n, m, r = map(int, input().split())
t = list(map(int, input().split()))

graph = [[] for _ in range(n + 1)]
for _ in range(r):
    a, b, c = map(int, input().split())
    graph[a].append((c, b))
    graph[b].append((c, a))

def dijkstra(node:int, search:int):
    visited = [False] * (n + 1)
    visited[node] = True
    pq = list(graph[node])
    heapify(pq)

    while pq:
        cost, c_node = heappop(pq)
        if cost > search:
            continue
        if visited[c_node]:
            continue
        
        visited[c_node] = True
        for n_cost, n_node in graph[c_node]:
            heappush(pq, (cost + n_cost, n_node))
    
    total = 0
    for i in range(1, n + 1):
        if visited[i]:
            total += t[i - 1]
    
    return total

results = [0] * (n + 1)
for i in range(1, n + 1):
    results[i] = dijkstra(i, m)

print(max(results))
