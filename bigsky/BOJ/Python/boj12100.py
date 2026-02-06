# BOJ12100: 2048 (Easy)
import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
ans = 0

# 보드를 시계 방향으로 90도 회전
def rotate(b):
    return [list(row) for row in zip(*b[::-1])]

# 보드를 왼쪽으로 밈
def move_left(b):
    new_board = []
    for row in b:
        # 1. 0이 아닌 숫자만 추출
        temp = [x for x in row if x != 0]

        # 2. 합치기
        merged_row = []
        skip = False
        for i in range(len(temp)):
            if skip:
                skip = False
                continue
            if i + 1 < len(temp) and temp[i] == temp[i+1]:
                merged_row.append(temp[i] * 2)
                skip = True
            else:
                merged_row.append(temp[i])

        # 3. 남은 빈칸 0으로 채우기
        merged_row += [0] * (N - len(merged_row))
        new_board.append(merged_row)

    return new_board

def dfs(current_board, count):
    global ans

    current_max = 0
    for row in current_board:
        current_max = max(current_max, max(row))
    ans = max(ans, current_max)

    if count == 5:
        return

    temp_board = current_board
    for _ in range(4):
        temp_board = rotate(temp_board)
        next_board = move_left(temp_board)

        if next_board != temp_board:
            dfs(next_board, count + 1)

dfs(board, 0)
print(ans)
