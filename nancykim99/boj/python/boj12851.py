'''
BOJ12851 : 숨바꼭질 2 (G4)

해결 방법 : 
bfs에 visited를 보면서, 만약 목적지에 있고, visited가 동일하면 +1 / 적으면 다시 0
'''
import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())

def bfs(n, m):
    q = deque()
    q.append(n)
    visited = [-1] * 100001
    visited[n] = 0
    mintime = 0
    cnt = 0
    while q:
        t = q.popleft()
        if t == m:
            if cnt == 0:
                mintime = visited[t]
                cnt = 1
            elif visited[t] == mintime:
                cnt += 1
            continue
        for ni in (t - 1, t + 1, t * 2):
            if 0 <= ni <= 100000:
                if visited[ni] == -1:
                    visited[ni] = visited[t] + 1
                    q.append(ni)
                elif visited[ni] == visited[t] + 1:
                    q.append(ni)
    return mintime, cnt

if n == m:
    print(0)
    print(1)
else:
    t, w = bfs(n, m)
    print(t)
    print(w)