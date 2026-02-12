#BOJ3020(D2): 개똥벌레
import sys
input = sys.stdin.readline

N, H = map(int, input().split())

bottom_counts = [0] * (H + 2)
top_counts = [0] * (H + 2)

for i in range(N):
    h = int(input())
    if i % 2 == 0:
        bottom_counts[h] += 1
    else:
        top_counts[h] += 1

for i in range(H, 0, -1):
    bottom_counts[i] += bottom_counts[i+1]
    top_counts[i] += top_counts[i+1]

min_obs = float('inf')
cnt = 0

for i in range(1, H+1):
    current_obs = bottom_counts[i] + top_counts[H - i + 1]

    if current_obs < min_obs:
        min_obs = current_obs
        cnt = 1
    elif current_obs == min_obs:
        cnt += 1

print(min_obs, cnt)