import sys

input = sys.stdin.readline

N, d, k, c = map(int, input().split())

# 회전초밥 일렬로 쫙 핌
sushis = [0] * (N + k + 1)
for i in range(N):
    sushi = int(input())
    sushis[i] = sushi
for i in range(k):
    sushis[N + i] = sushis[i]

eating = [0] * (d + 1)
eating[c] = 999  # 쿠폰은 이미 먹었다 가정
now_eating = 1

# 처음부터 k개까지 먹어보기
for i in range(k):
    eat = sushis[i]
    if eating[eat] == 0:
        now_eating += 1
    eating[eat] += 1

max_eating = now_eating

for i in range(N):
    # 게워내기
    vomit = sushis[i]
    if eating[vomit] == 1:
        now_eating -= 1
    eating[vomit] -= 1

    # 먹기
    eat = sushis[i + k]
    if eating[eat] == 0:
        now_eating += 1
    eating[eat] += 1

    # 최고기록 갱신
    max_eating = max(max_eating, now_eating)

print(max_eating)
