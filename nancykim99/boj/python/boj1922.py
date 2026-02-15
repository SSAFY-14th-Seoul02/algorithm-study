'''
BOJ1922 : 네트워크 연결 (G4)

해결 방법 : 
사이클을 전부 연결하면서, 최소 비용을 찾아야 하기 때문에, MST 크루스칼 알고리즘으로 풀기
'''
import sys
input = sys.stdin.readline

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, a, b):
    a = find(parent, a)
    b = find(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

n = int(input())
m = int(input())
parent = [i for i in range(n + 1)]
edges = []
total_cost = 0

for _ in range(m):
    s, e, w = map(int, input().split())
    edges.append((w, s, e))

edges.sort()

for w, s, e in edges:
    if find(parent, s) != find(parent, e):
        union(parent, s, e)
        total_cost += w

print(total_cost)