'''
BOJ3190 : 뱀 (G4)

해결 방법 : 
방향 :
    0, 1 -> L : -1, 0 / D : 1, 0 
    0, -1 -> L : 1, 0 / D : -1, 0
    1, 0 -> L : 0, 1 / D : 0, -1
    -1, 0 -> L : 0, -1 / D : 0, 1
    
메모 : 
현재 시간복잡도 : 112ms / 113500kb
    n = 100 -> 최대 이동 : 10000번
    매 이동 : turn() + global 조회 + move_head() 호출
    함수 호출 오버헤드 * 10000번
최적화 방법 : 
    1. while 루프로 함수 제거, 인라인 루프
    2. if를 elif로 변경하여 불필요한 조건 검사 제거
    3. turn_arr를 dict로 바꾸어 함수가 아닌 루프 내에 검사 방법으로 변경
'''
import sys
input = sys.stdin.readline
from collections import deque

# 보드의 크기 N
n = int(input())
hi, hj = 0, 0 # 뱀 머리 위치 
cnt = 0 # 초 시간 
# 사과의 개수 K
k = int(input())
dummy = [[0] * (n+1) for _ in range(n+1)]
# 사과의 위치 (행, 열)
for _ in range(k):
    x, y = map(int, input().split())
    dummy[x-1][y-1] = 1
# 뱀의 방향 변환 횟수
snake_turn = int(input())
turn_arr = deque()
for _ in range(snake_turn):
    sec, direction = input().split()
    sec = int(sec)
    turn_arr.append((sec,direction))

# 방향 바꾸기
turn_dir = 0
dirs = [(0,1), (1,0), (0,-1), (-1,0)]
def turn(dirs, turn_dir):
    global cnt
    if turn_arr and cnt == turn_arr[0][0]:
        if turn_arr[0][1] == 'L':
            turn_arr.popleft()
            return (turn_dir - 1) % 4
        else:
            turn_arr.popleft()
            return (turn_dir + 1) % 4
    return turn_dir

snake = deque()
snake.append((0, 0))
dummy[0][0] = 2
# 머리 전진
def move_head():
    global hi, hj, cnt, turn_dir
    turn_dir = turn(dirs, turn_dir)
    hi, hj = hi + dirs[turn_dir][0], hj + dirs[turn_dir][1]
    # 칸에 뱀이 이미 있을 때 또는 벽에 부딪혔을 때
    if not (0 <= hi < n and 0 <= hj < n) or dummy[hi][hj] == 2:
        cnt += 1
        return False
    # 칸이 비어있을 때
    if dummy[hi][hj] == 0:
        dummy[hi][hj] = 2
        snake.append((hi, hj))
        ti, tj = snake.popleft()
        dummy[ti][tj] = 0
        cnt += 1
    # 칸에 사과가 있을 때
    if dummy[hi][hj] == 1:
        dummy[hi][hj] = 2
        snake.append((hi, hj))
        cnt += 1
    return True
    
while move_head():
    pass

print(cnt)