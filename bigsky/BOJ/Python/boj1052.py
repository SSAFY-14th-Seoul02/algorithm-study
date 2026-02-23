# BOJ1052: 물병
import sys
input = sys.stdin.readline

N, K = map(int, input().split())

cnt = 0
while bin(N).count('1') > K:
    lowest_bit = N & -N
    N += lowest_bit
    cnt += lowest_bit

print(cnt)