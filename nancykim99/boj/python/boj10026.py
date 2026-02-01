'''
BOJ10026 : 적록색약 (G5)

해결 방법 : 
bfs 코드를 적록색약 버전과 일반 버전으로 만들어서 해결

메모 : 
시간과 메모리를 줄일 수 있는 방법
1. 적록색약 버전으로 arr을 만들어서 돌리면 bfs를 하나 더 만드는 수고를 줄일 수 있음
2. 첫번째 탐색이 끝나면 visited 배열을 초기화 해서 다시 사용하는 방식으로 메모리를 줄일 수 있음
3. 상하좌우 좌표를 따로 빼놓으면 미세하게 시간을 단축할 수 있음
'''
import sys
from collections import deque
input = sys.stdin.readline

def bfs(x, y):
    q = deque()
    q.append((x, y))
    see[x][y] = 1
    while q:
        ti, tj = q.popleft()
        for si, sj in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
            ni, nj = ti + si, tj + sj
            if 0 <= ni < n and 0 <= nj < n:
                if arr[ni][nj] == arr[ti][tj] and not see[ni][nj]:
                    see[ni][nj] = 1
                    q.append((ni, nj))
                    
def bfs_no_see(x, y):
    q = deque()
    q.append((x, y))
    no_see[x][y] = 1
    while q:
        ti, tj = q.popleft()
        if arr[ti][tj] == "R" or arr[ti][tj] == "G":
            for si, sj in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                ni, nj = ti + si, tj + sj
                if 0 <= ni < n and 0 <= nj < n:
                    if arr[ni][nj] == "R" or arr[ni][nj] == "G":
                        if not no_see[ni][nj]:
                            no_see[ni][nj] = 1
                            q.append((ni, nj))
        else:
            for si, sj in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                ni, nj = ti + si, tj + sj
                if 0 <= ni < n and 0 <= nj < n:
                    if arr[ni][nj] == arr[ti][tj] and not no_see[ni][nj]:
                        no_see[ni][nj] = 1
                        q.append((ni, nj))

n = int(input())
arr = [list(input().strip()) for _ in range(n)]

see = [[0] * n for _ in range(n)]
no_see = [[0] * n for _ in range(n)]

cnt = 0
no_cnt = 0
for i in range(n):
    for j in range(n):
        if not see[i][j]:
            bfs(i, j)
            cnt += 1
        if not no_see[i][j]:
            bfs_no_see(i, j)
            no_cnt += 1

print(cnt, no_cnt)