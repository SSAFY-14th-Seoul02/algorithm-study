'''
BOJ3020 : 개똥벌레 (G5)

해결 방법 : 
누적합으로 미리 각각 구해놓고, 돌리면서 파괴하는 거 구하기
'''
import sys
input = sys.stdin.readline

n, h = map(int, input().split())

low = [0] * (h + 1)
high = [0] * (h + 1)

for i in range(n):
    a = int(input())
    if i % 2 == 0:
        low[a] += 1
    else:
        high[a] += 1
        
for i in range(h - 1, 0, -1):
    low[i] += low[i + 1]
    high[i] += high[i + 1]

min_n = float('inf')
cnt = 0

for i in range(1, h + 1):
    total = low[i] + high[h - i + 1]
    
    if min_n > total:
        min_n = total
        cnt = 1
    elif min_n == total:
        cnt += 1

print(min_n, cnt)