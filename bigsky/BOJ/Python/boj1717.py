# BOJ1717: 집합의 표현
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n, m = map(int, input().split())

parent = [i for i in range(n + 1)]

def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    rootA = find(a)
    rootB = find(b)
    parent[max(rootA, rootB)] = min(rootA, rootB)

for _ in range(m):
    cmd, a, b = map(int, input().split())
    if cmd == 0:
        union(a, b)
    else:
        print("YES" if find(a) == find(b) else "NO")