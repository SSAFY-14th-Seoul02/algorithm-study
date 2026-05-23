'''
PGM250136 : 석유 시추 (LV2)

해결 방법 : 
bfs로 1인 칸만 확인하면서, 그 하나의 덩어리의 사이즈 및 하나의 덩어리가 차지하는 컬럼들의 그룹을 찾음
그 사이즈와 그 컬럼들을 업데이트하며, 가장 많은 사이즈를 가지고 있는 컬럼만 반환
'''
from collections import deque
def solution(land):
    n = len(land)
    m = len(land[0])
    visited = [[0] * m for _ in range(n)]
    columns = [0] * m
    def bfs(i, j):
        q = deque([])
        column = set()
        q.append((i, j))
        visited[i][j] = 1
        column.add(j)
        size = 1
        while q:
            ti, tj = q.popleft()
            for si, sj in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                ni, nj = ti + si, tj + sj
                if 0<=ni<n and 0<=nj<m and land[ni][nj] == 1 and not visited[ni][nj]:
                    q.append((ni, nj))
                    visited[ni][nj] = 1
                    column.add(nj)
                    size += 1
        for c in column:
            columns[c] += size
    for i in range(n):
        for j in range(m):
            if land[i][j] == 1 and not visited[i][j]:
                bfs(i, j)
    answer = max(columns)
    return answer