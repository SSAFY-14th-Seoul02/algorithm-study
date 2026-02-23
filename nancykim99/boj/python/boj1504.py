'''
BOJ1504 : 특정한 최단 경로 (G4)

해결 방법 : 
다익스트라로 1번 노드에서 n번 노드까지 최단 경로 구하기
v1과 v2를 지났는지 확인하기
'''
import sys, heapq
input = sys.stdin.readline

inf = int(1e9)

n, e = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for i in range(e):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))
    graph[b].append((a, w))

v1, v2 = map(int, input().split())

def dijkstra(graph, start, n):
    dist = [inf] * (n + 1)
    dist[start] = 0
    pq = [(0, start)]
    while pq:
        c_dist, u = heapq.heappop(pq)
        if c_dist > dist[u]:
            continue
        for v, w in graph[u]:
            cost = c_dist + w
            if cost <= dist[v]:
                dist[v] = cost
                heapq.heappush(pq, (cost, v))
    return dist

dist = dijkstra(graph, 1, n)

if dist[v1] != 0 and dist[v2] != 0:
    print(dist[n])
else:
    print(-1)