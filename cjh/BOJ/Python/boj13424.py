import sys

INF = 1e9

t = int(sys.stdin.readline().strip())
for _ in range(t):
    n, m = list(map(int, sys.stdin.readline().strip().split()))

    graph = [[INF for _ in range(n+1)] for _ in range(n+1)]
    for i in range(1, n+1):
        graph[i][i] = 0

    for __ in range(m):
        a, b, c = list(map(int, sys.stdin.readline().strip().split()))
        graph[a][b] = c
        graph[b][a] = c

    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

    k = int(sys.stdin.readline().strip())
    friends = list(map(int, sys.stdin.readline().strip().split()))

    res = 0
    min_distance = INF
    for i in range(1, n+1):
        temp = 0
        for f in friends:
            temp += graph[f][i]

        if temp < min_distance:
            min_distance = temp
            res = i

    print(res)