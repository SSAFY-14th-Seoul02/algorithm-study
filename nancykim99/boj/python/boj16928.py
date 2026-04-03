'''
BOJ16928 : 뱀과 사다리 게임 (G5)

해결 방법 : 
1차원 bfs로 돌면서, 주사위만큼 하나씩 가보기

메모 : 
- `"<function finish_game at 0x00007f87881823e0>` : 함수 호출에 () 안 붙였을 때 생기는 에러
현재 시간복잡도 : O(600) / 공간복잡도 : O(300)
    노드 수 = 100개 (칸 1~100)
    각 노드 간선 = 최대 6개 (주사위 1~6)
    BFS 순회 = 각 노드 정확히 1번만 처리
    전역변수 탐색 = 매 루프마다 global scope 탐색 발생
    board 초기화 = 100번 append() 동적 메모리 재할당 * 100번
최적화 방법 :
    1. game_board = list(range(100)) 으로 한 번에 초기화
       → append() 100번 호출 제거, 메모리 한 번에 할당
    2. 전역변수 game_board → 함수 인자 board로 전달
       → 매 루프마다 global scope 탐색 → local scope 탐색으로 단축
    3. visited[0]=1 시작 → dist[-1] 미방문 표시로 변경
       → print(finish_game() - 1) 의 -1 연산 제거, 가독성 향상
    4. q = deque([0]) 선언과 동시에 초기화
       → deque() + append(0) 2번 호출 → 1번으로 단축

'''
import sys
input = sys.stdin.readline
from collections import deque

game_board = []
for i in range(100):
    game_board.append(i)
    
n, m = map(int, input().split())

for _ in range(n):
    s, e = map(int, input().split())
    game_board[s - 1] = e - 1

for _ in range(m):
    s, e = map(int, input().split())
    game_board[s - 1] = e - 1


def finish_game():
    q = deque()
    q.append(0)
    visited = [0] * 100
    visited[0] = 1
    while q:
        ti = q.popleft()
        if ti == 99:
            return visited[ti]
        for i in range(1, 7):
            ni = ti + i
            if ni >= 100:
                continue
            ni = game_board[ni]
            if visited[ni] == 0:
                visited[ni] = visited[ti] + 1
                q.append(ni)

print(finish_game() - 1)