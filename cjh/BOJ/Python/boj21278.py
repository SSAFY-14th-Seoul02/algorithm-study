"""
bfs로 start, end 거리 찾기
dp로 최적화
bfs 시, visited로 최적화
"""

import sys
from itertools import combinations

n, m = list(map(int, sys.stdin.readline().strip().split()))

edges = []
for _ in range(m):
    edges.append(list(map(int, sys.stdin.readline().strip().split())))

graph = {}
for i in range(1, n+1):
    graph[i] = []

for edge in edges:
    graph[edge[0]].append(edge[1])
    graph[edge[1]].append(edge[0])

dp = [["NONE" for _ in range(n+1)] for _ in range(n+1)]

def find_distance(s, e):
    visited = [False for _ in range(n + 1)]

    q = [[s, 0]]
    visited[s] = True

    while q:
        cur = q.pop(0)
        if cur[0] == e:
            dp[s][e] = cur[1] * 2
            dp[e][s] = cur[1] * 2
            return cur[1] * 2

        for node in graph[cur[0]]:
            if not visited[node]:
                q.append([node, cur[1] + 1])
                visited[node] = True

nodes = [i for i in range(1, n+1)]
combs = list(combinations(nodes, 2))

res = []
for c1, c2 in combs:
    d_total = 0
    for i in range(1, n+1):
        if dp[i][c1] != "NONE":
            temp1 = dp[i][c1]
        elif dp[c1][i] != "NONE":
            temp1 = dp[c1][i]
        else:
            temp1 = find_distance(i, c1)

        if dp[i][c2] != "NONE":
            temp2 = dp[i][c2]
        elif dp[c2][i] != "NONE":
            temp2 = dp[c2][i]
        else:
            temp2 = find_distance(i, c2)

        d_total += min(temp1, temp2)
    res.append([c1, c2, d_total])

res.sort(key=lambda x: (x[2], x[0], x[1]))

for each in res[0]:
    print(each, end=" ")