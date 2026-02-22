'''
BOJ1753 : 최단경로 (G4)

해결 방법 : 
단방향 다익스트라로 최단 경로 찾기
모든 노드 돌면서 k까지의 거리 출력
'''
import sys, heapq
input = sys.stdin.readline
inf = int(1e9)

n, r = map(int, input().split())
k = int(input())
graph = [[] for _ in range(n + 1)]

for i in range(r):
    s, e, w = map(int, input().split())
    graph[s].append((e, w))

def dijkstra(graph, start, n):
    dist = [inf] * (n + 1)
    dist[start] = 0
    pq = [(0, start)]
    while pq:
        c_dist, u = heapq.heappop(pq)
        if c_dist > dist[u]:
            continue
        for nv, w in graph[u]:
            cost = c_dist + w
            if cost >= dist[nv]:
                continue
            dist[nv] = cost
            heapq.heappush(pq, (cost, nv))
    return dist

dist = dijkstra(graph, k, n)

for i in range(1, n + 1):
    if dist[i] == inf:
        print("INF")
    else:
        print(dist[i])