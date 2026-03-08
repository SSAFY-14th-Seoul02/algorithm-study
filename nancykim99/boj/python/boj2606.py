'''
BOJ2606 : 바이러스 (S3)

해결 방법 : 
유니온 파인드로 각 노드의 루트를 찾아, 연결이 되어 있는지 안 되어 있는지 확인 -> 각 노드의 루트가 1인 경우에만 cnt
'''
import sys
input = sys.stdin.readline

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    px, py = find(x), find(y)
    if px == py:
        return
    if px < py:
        parent[py] = px
    else:
        parent[px] = py

v = int(input())
e = int(input())
parent = [0] * (v + 1)
for i in range(1, v + 1):
    parent[i] = i

for _ in range(e):
    i, j = map(int, input().split())
    union(i, j)

cnt = 0
for i in range(1, v + 1):
    # 1이 루트이고, 1번 자기 자신이 아닐때
    if find(i) == find(1) and i != 1:
        cnt += 1

print(cnt)