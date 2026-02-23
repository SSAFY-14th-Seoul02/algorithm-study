'''
BOJ14938 : 서강그라운드 (G4)

해결 방법 : 
다익스트라로 내가 갈 수 있는 곳들을 다 확인하기
거리 중 기준보다 작거나 같은 경우만 item을 더하기
최대로 얻을 수 있는 item을 구하기
'''
import sys
import heapq
input = sys.stdin.readline
inf = int(1e9)

n, m, r = map(int, input().split())
items = [0] + list(map(int, input().split()))
weights = [[] for _ in range(n + 1)]
visited = [0] * (n + 1)

for i in range(r):
    s, e, w = map(int, input().split())
    weights[s].append((e, w))
    weights[e].append((s, w))

def dijkstra(graph, start):
    item_sum = 0
    dist = [inf] * (n + 1)
    dist[start] = 0
    pq = [(0, start)]
    while pq:
        current_dist, u = heapq.heappop(pq)
        if current_dist > dist[u]:
            continue
        if current_dist > m:
            continue
        for v, w in graph[u]:
            cost = current_dist + w
            if cost < dist[v]:
                dist[v] = cost
                heapq.heappush(pq, (cost, v)) 
    for i in range(n + 1):
        if dist[i] <= m:
            item_sum += items[i]
    return item_sum

ans = 0
for i in range(1, n + 1):
    min_ans = dijkstra(weights, i)
    if ans < min_ans:
        ans = min_ans

print(ans)