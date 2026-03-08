'''
BOJ14500 : 테트로미노 (G4)

해결 방법 :
T자 빼고 나머지는 깊이우선으로 확인하기 -> T의 경우, 깊이우선으로 해결할 수 없기에 따로 확인
'''
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

visited = [[0] * m for _ in range(n)]
ans = 0

def dfs(x, y, cnt, numSum):
    global ans
    if cnt == 4:
        ans = max(ans, numSum)
        return ans
    for si, sj in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        ni, nj = x + si, y + sj
        if 0 <= ni < n and 0 <= nj < m and not visited[ni][nj]:
            visited[ni][nj] = 1
            dfs(ni, nj, cnt + 1, numSum + grid[ni][nj])
            visited[ni][nj] = 0

T_shapes = [
    [(0,0),(1,0),(-1,0),(0,1)],   # ㅗ
    [(0,0),(1,0),(-1,0),(0,-1)],  # ㅜ
    [(0,0),(0,1),(0,-1),(1,0)],   # ㅓ
    [(0,0),(0,1),(0,-1),(-1,0)],  # ㅏ
]

def check_T(x, y):
    total = 0
    for shape in T_shapes:
        s = 0
        valid = True
        for dx2, dy2 in shape:
            nx, ny = x + dx2, y + dy2
            if 0 <= nx < n and 0 <= ny < m:
                s += grid[nx][ny]
            else:
                valid = False
                break
        if valid:
            total = max(total, s)
    return total

for i in range(n):
    for j in range(m):
        visited[i][j] = 1
        dfs(i, j, 1, grid[i][j])
        visited[i][j] = 0
        ans = max(ans, check_T(i, j))

print(ans)