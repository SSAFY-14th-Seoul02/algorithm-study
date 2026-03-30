'''
BOJ14940 : 쉬운 최단거리 (S1)

해결 방법 : 
visited을 -1로 만들어 0, 시작점을 미리 표시하기
그 외의 곳을 지날때마다 바로 전 기준칸 + 1 로 visited에 표시하기
'''
import sys
from collections import deque

input = sys.stdin.readline

def bfs(x, y):
    q = deque()
    q.append((x, y))
    visited[x][y] = 0
    while q:
        qi, qj = q.popleft()
        for di, dj in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
            ni = di + qi
            nj = dj + qj
            if 0 <= ni < n and 0 <= nj < m:
                if arr[ni][nj] != 0 and visited[ni][nj] == -1:
                    q.append((ni, nj))
                    visited[ni][nj] = visited[qi][qj] + 1

    return visited

n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
visited = [[-1] * (m) for _ in range(n)]

for i in range(n):
    for j in range(m):
        if arr[i][j] == 2:
            si, sj = i, j
        if arr[i][j] == 0:
            visited[i][j] = 0

ans = bfs(si, sj)

for i in range(n):
    print(" ".join(map(str, ans[i])))