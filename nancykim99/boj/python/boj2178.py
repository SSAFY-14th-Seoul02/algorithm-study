'''
BOJ2178 : 미로 탐색 (S1)

해결 방법 : 
BFS로 n,m 의 거리를 구하기
'''
import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [list(input()) for _ in range(n)]
visited = [[0] * m for _ in range(n)]

def bfs():
    q = deque()
    visited[0][0] = 1
    q.append((0, 0))
    while q:
        ti, tj = q.popleft()
        for si, sj in [(0,1), (1,0), (0,-1), (-1,0)]:
            ni, nj = ti + si, tj + sj
            if 0 <= ni < n and 0 <= nj < m:
                if arr[ni][nj] == "1" and not visited[ni][nj]:
                    q.append((ni, nj))
                    visited[ni][nj] = visited[ti][tj] + 1
    return visited[n-1][m-1]

ans = bfs()

print(ans)