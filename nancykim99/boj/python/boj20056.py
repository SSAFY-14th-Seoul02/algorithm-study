'''
BOJ20056 : 마법사 상어와 파이어볼 (G4)

해결 방법 : 
r, c, m, d, s
(r, c) : 파이어볼 위치
w : 질량
d : 방향
s : 속력 (s 칸만큼 d 방향으로 이동)

1칸에 2개 이상의 파이어볼이 있는 경우 : 
1. 같은 칸 -> 1개로 합쳐짐
2. 4개로 나누어짐
3. 질량은 모두 합쳐진 질량 합 / 5
4. 속력은 모두 합쳐진 속력 합 / 합쳐진 파이어볼의 개수
5. 방향이 모두 홀수 / 짝수 -> 방향 = 0, 2, 4, 6
6. 방향이 다 다른 경우 -> 방향 = 1, 3, 5, 7
7. 질량 = 0은 사라짐

전부 다 이동시킨 이후, 만약 2차원에 2개 이상 들어있는 경우가 있으면, 구현 진행하기
'''
import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
# n * n의 map
arr = [[0] * n for _ in range(n)]
arr_n = [[[] for _ in range(n)] for _ in range(n)] # n개 확인용 arr
# 방향 (0 ~ 8)
dir = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

for _ in range(m):
    r, c, w, s, d = map(int, input().split())
    di, dj = dir[d]
    nr, nc = r + (di * s), c + (dj * s)
    arr[nr][nc].append((w, s, d))
    arr_n[nr][nc] += 1

flag_d = False
fi, fj = -1, -1
def finddouble(m):
    for i in range(m):
        for j in range(m):
            if arr_n[i][j] > 1:
                flag_d = True
                fi, fj = i, j
                break
    return 0

while finddouble(m) != 0:
    if finddouble(m) == 0:
        break
    num_fire = arr_n[fi][fj]
    sum_w = 0
    sum_s = 0
    all_dir = []
    ndir = []
    for i in range(num_fire):
        sum_w += arr[fi][fj][i][0]
        sum_s += arr[fi][fj][i][1]
        all_dir.append(arr[fi][fj][i][2])
    fire_w = sum_w // 5
    if fire_w <= 0:
        continue
    else:
        fire_s = sum_s // num_fire
        for i in range(all_dir):
            if ((i % 2 == 1) and (i % 2 == 1)) or ((i % 2 == 0) and (i % 2 == 0)):
                ndir = [0, 2, 4, 6]
            else:
                ndir = [1, 3, 5, 7]
        arr[fi][fj] = 0
        for i in ndir:
            nnr, nnc = nr + (dir[i][0] * fire_s), nc + (dir[i][1] * fire_s)
            arr[nnr][nnc].append((fire_w, i, fire_s))
            arr_n[nnr][nnc] += 1

ans = 0
for i in range(m):
    for j in range(m):
        if arr[i][j] != 0:
            ans += arr[i][j][0][0]

print(ans)