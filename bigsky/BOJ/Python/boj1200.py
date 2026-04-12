# BOJ1200: 기상예측
import sys
from itertools import combinations

input = sys.stdin.readline
N, M, R, S = map(int, input().split())

board = []
max_val = 0
for _ in range(N):
    row = list(map(int, input().split()))
    board.append(row)
    max_val += sum(row)

col_slice_sum = [[[0] * M for _ in range(N)] for _ in range(N)]
for c in range(M):
    for i in range(N):
        s = 0
        for j in range(i, N):
            s += board[j][c]
            col_slice_sum[i][j][c] = s

comb_data = []
for cuts in combinations(range(1, N), R):
    intervals = []
    prev = 0
    for cut in cuts:
        intervals.append((prev, cut - 1))
        prev = cut
    intervals.append((prev, N - 1))

    col_sums_for_comb = []
    max_single_col_sum = 0
    for c in range(M):
        c_sums = [col_slice_sum[start][end][c] for start, end in intervals]
        col_sums_for_comb.append(c_sums)

        c_max = max(c_sums)
        if c_max > max_single_col_sum:
            max_single_col_sum = c_max

    comb_data.append((max_single_col_sum, col_sums_for_comb))

left = 0
right = max_val
answer = max_val

while left <= right:
    mid = (left + right) // 2
    possible = False

    for max_single, col_sums_for_comb in comb_data:
        if max_single > mid:
            continue

        current_sum = [0] * (R + 1)
        cut_count = 0
        is_valid = True

        for c in range(M):
            c_sums = col_sums_for_comb[c]
            need_cut = False

            for i in range(R + 1):
                if current_sum[i] + c_sums[i] > mid:
                    need_cut = True
                    break

            if need_cut:
                cut_count += 1
                if cut_count > S:
                    is_valid = False
                    break
                current_sum = c_sums[:]
            else:
                for i in range(R + 1):
                    current_sum[i] += c_sums[i]

        if is_valid:
            possible = True
            break

    if possible:
        answer = mid
        right = mid - 1
    else:
        left = mid + 1

print(answer)