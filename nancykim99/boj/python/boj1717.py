'''
BOJ1717 : 집합의 표현 (G5)

해결 방법 : 
0일때는 union으로 집합 합치기, 찾을 때는 부모를 확인해서 집합 내 부모 찾기
'''

import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

n, m = map(int, input().split())
parent = [i for i in range(n + 1)]

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

for _ in range(m):
    x, i, j = map(int, input().split())
    if x == 0:
        union(i, j)
    else:
        if find(i) == find(j):
            print("YES")
        else:
            print("NO")