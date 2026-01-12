'''
BOJ2589 : 보물섬 (G5)

해결 방법 : bfs로 L을 다 돌려 max 거리를 찾은 후, 저장. 저장한 것들 중에서 max를 찾기.
'''

from collections import deque

n, m = map(int, input().split())
grid = [list(input().strip()) for _ in range(n)]

def bfs(li, lj):
    visited = [[0]*m for _ in range(n)]
    q = deque([(li, lj)])
    while q:
        ti, tj = q.popleft()
        for vi, vj in [(0,1), (1,0), (0,-1), (-1,0)]:
            ni, nj = ti + vi, tj + vj
            if 0<=ni<n and 0<=nj<m and grid[ni][nj] == 'L' and not visited[ni][nj]:
                q.append((ni, nj))
                visited[ni][nj] = visited[ti][tj] + 1
    return max(map(max, visited))

ans = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == 'L':
            temp = bfs(i, j)
            if temp > ans:
                ans = temp

print(ans)
