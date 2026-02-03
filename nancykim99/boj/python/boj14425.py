'''
BOJ14425 : 문자열 집합 (S4)

해결 방법 : 
해시를 사용한 집합과 맵 -> dict, set으로 해결
'''
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
s = set()

for _ in range(n):
    a = input()
    s.add(a)

ans = 0
for _ in range(m):
    b = input()
    if b in s:
        ans += 1

print(ans)
