"""
# [Silver III] 체스판 다시 칠하기 - 1018

[문제 링크](https://www.acmicpc.net/problem/1018)

### 성능 요약

메모리: 110968 KB, 시간: 112 ms

### 분류

구현, 브루트포스 알고리즘

### 제출 일자

2026년 4월 6일 20:06:54

### 문제 설명

<p>지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M×N 크기의 보드를 찾았다. 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8×8 크기의 체스판으로 만들려고 한다.</p>

<p>체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.</p>

<p>보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8×8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.</p>

### 입력

 <p>첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.</p>

### 출력

 <p>첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.</p>


"""

answer_list = [
    ['BW' * 4  , 'WB' * 4] * 4,
    ['WB' * 4  , 'BW' * 4] * 4,
]

min_cnt = float('INF')

N, M = map(int, input().split())
board = [input() for _ in range(N)]


for i in range(N - 8 + 1):
    for j in range(M - 8 + 1):
        # 1: answer_list[0]과 비교
        first_cnt = 0
        # 2: answer_list[1]과 비교
        second_cnt = 0

        for r in range(i, i + 8):
            for c in range(j, j + 8):
                if answer_list[0][r - i][c - j] != board[r][c]:
                    first_cnt += 1
                if answer_list[1][r - i][c - j] != board[r][c]:
                    second_cnt += 1

        min_cnt = min(min_cnt, first_cnt, second_cnt)


print(min_cnt)

'''
축약 버전
index 별로 비교해서 a == b: true/1, a != false/0임을 이용해서 연산
'''

for i in range(N - 8 + 1):
    for j in range(M - 8 + 1):
        first_cnt = second_cnt = 0
        for r in range(8):
            window_row = board[i + r][j:j + 8]
            first_cnt += sum(a != b for a,b in zip(answer_list[0][r], window_row))
            second_cnt += sum(a != b for a,b in zip(answer_list[1][r], window_row))

        min_cnt = min(min_cnt, first_cnt, second_cnt)


print(min_cnt)
