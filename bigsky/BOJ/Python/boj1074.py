# BOJ1074(D3): Z
import sys
input = sys.stdin.readline

N, r, c = map(int, input().split())

# 사분면을 체크하는 함수
# 1사분면=1 / 2사분면=0 / 3사분면=2 / 4사분면=3
# 이후 계산할 때 해당 반환값만큼 곱해줄 예정
def check_quadrant(N, r, c):
    if r < 2**(N-1) and c >= 2**(N-1):
        nr, nc = r, c - 2**(N-1)
        return 1, nr, nc
    elif r < 2**(N-1) and c < 2**(N-1):
        nr, nc = r, c
        return 0, nr, nc
    elif r >= 2**(N-1) and c < 2**(N-1):
        nr, nc = r - 2**(N-1), c
        return 2, nr, nc
    else:
        nr, nc = r - 2**(N-1), c - 2**(N-1)
        return 3, nr, nc

def solve(N, r, c, total):
    if N == 0:
        print(total)
        sys.exit()

    times, nr, nc = check_quadrant(N, r, c)
    n_total = total + 4**(N-1) * times

    solve(N-1, nr, nc, n_total)

solve(N, r, c, 0)