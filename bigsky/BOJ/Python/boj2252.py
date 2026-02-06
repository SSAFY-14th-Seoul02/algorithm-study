# BOJ2252: 줄 세우기
from collections import defaultdict, deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())

indeg = [0] * (N + 1)
graph = defaultdict(list)

for _ in range(M):
    A, B = map(int, input().split())
    indeg[B] += 1
    graph[A].append(B)

q = deque()
for i in range(1, N + 1):
    if indeg[i] == 0:
        q.append(i)

while q:
    now = q.popleft()
    print(now, end=' ')

    for n_node in graph[now]:
        indeg[n_node] -= 1
        if indeg[n_node] == 0:
            q.append(n_node)
