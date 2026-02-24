# BOJ3109(D3): 빵집
import sys
input = sys.stdin.readline

DR = (1, 0, -1)

R, C = map(int, input().split())
arr = list([False] * C for _ in range(R))
for r in range(R):
    row = input().rstrip()
    for c in range(C):
        if row[c] == 'x':
            arr[r][c] = True

def dfs(sr):
    stack = [(sr, 0)]
    while stack:
        cr, cc = stack.pop()
        arr[cr][cc] = True
        if cc == C - 1:
            return True
        for d in range(3):
            nr, nc = cr + DR[d], cc + 1
            if not (0 <= nr < R and 0 <= nc < C):
                continue
            if arr[nr][nc]:
                continue
            stack.append((nr, nc))
    return False

cnt = 0
for i in range(R):
    if dfs(i):
        cnt += 1
    
print(cnt)