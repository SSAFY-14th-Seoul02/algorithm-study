'''
BOJ20040 : 사이클 게임 (G4)

해결 방법 : 
유니온 파인드를 한 후, 조건문으로 해결
find 함수 : 기존에는 재귀 함수 -> while 문 및 `parent[x] = parent[parent[x]]`로 2칸씩 점프하여 부모 노드 찾기
- 스택오버 위험 방지, 압축으로 경로 압축 진행
'''
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
parent = [i for i in range(n)]

def find(x):
    while parent[x] != x:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return parent[x]

def union(x, y):
    fx = find(x)
    fy = find(y)
    if fx == fy:
        return False
    parent[fy] = fx
    return True

ans = 0
for i in range(m):
    a, b = map(int, input().split())
    if not union(a, b):
        ans = i + 1
        break

print(ans)