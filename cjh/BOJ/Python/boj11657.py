import sys

n, m = list(map(int, sys.stdin.readline().strip().split()))

edges = []
for _ in range(m):
    edges.append(list(map(int, sys.stdin.readline().strip().split())))

INF = 1e9
d = [INF for i in range(n+1)]
d[1] = 0

flag = 0
for i in range(n):
    for edge in edges:
        a = edge[0]
        b = edge[1]
        c = edge[2]

        if d[a] != INF and d[a] + c < d[b]:
            if i == n-1:
                flag = 1
                break
            d[b] = d[a] + c

if flag:
    print(-1)
else:
    for number in d[2:]:
        if number == INF:
            print(-1)
        else:
            print(number)