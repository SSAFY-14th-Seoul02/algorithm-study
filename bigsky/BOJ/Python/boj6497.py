# BOJ6497(D2): 전력난
import sys
input = sys.stdin.readline

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, rank, a, b):
    a, b = find(parent, a), find(parent, b)
    if a == b:
        return False
    if rank[a] < rank[b]:
        a, b = b, a
    parent[b] = a
    if rank[a] == rank[b]:
        rank[a] += 1
    return True

while True:
    m, n = map(int, input().split())
    if m == 0 and n == 0:
        break

    edges = []
    total = 0

    for _ in range(n):
        x, y, z = map(int, input().split())
        edges.append((z, x, y))
        total += z
    
    edges.sort()

    parent = list(range(m + 1))
    rank = [0] * (m + 1)

    mst_cost = 0
    for cost, x, y in edges:
        if union(parent, rank, x, y):
            mst_cost += cost

    print(total - mst_cost)
