'''
BOJ1261 : 알고스팟 (G4)

해결 방법 : 
bfs에서 0이면 appendleft, 1이면 append하는 방식으로 0인 길을 먼저 가보기
1로 가는 경우, 거리를 갱신하고, 거리가 더 짧은 경우 갱신하기

메모 : 
현재 시간복잡도 : O(N × M) / 공간복잡도 : O(N × M)
    노드 수 V = N × M = 최대 100 × 100 = 10,000
    간선 수 E = 4 × N × M (상하좌우 4방향)
    0-1 BFS 1회 수행 = O(V + E) = O(5 × N × M) = O(N × M)
    각 칸은 new_cost < dist 조건일 때만 큐에 재추가
    deque 최대 크기 = O(N × M)
    방향벡터 [(0,1),(1,0),(0,-1),(-1,0)] = 루프마다 리스트 생성 발생
    float('inf') = 정수보다 느린 float 비교 연산
    board[ni][nj] = 2D 인덱싱 2번 접근
    dist[ti][tj] = 2D 인덱싱 2번 접근
    전역 dist, board = bfs() 내부에서 매번 LEGB 룰 탐색 발생

최적화 방법 :
    1. float('inf') → n * m + 1 정수로 변경
       → 벽 최대 개수 = 10,000 이므로 10,001이면 INF로 충분
       → 정수 비교가 float보다 빠름
    2. board 2D → 1D 평탄화 board.extend()
       → 2D 인덱싱 2번 → 1D 인덱싱 1번으로 단축
       → 메모리 연속 할당으로 캐시 히트율 향상
    3. dist 2D → 1D 평탄화
       → 동일하게 인덱싱 2번 → 1번으로 단축
    4. 방향벡터 DIRS = ((0,1),(1,0),(0,-1),(-1,0)) 전역 상수 선언
       → 루프 40,000번 리스트 생성 → 전역 1번 tuple 생성으로 단축
       → tuple이 list보다 메모리 적게 사용
    5. _dist = dist / _board = board 지역 바인딩
       → 전역 참조 LEGB 탐색 제거, 지역변수 접근이 더 빠름
    6. cur = ti * m + tj 루프 밖에서 1번만 계산
       → 매 방향 탐색마다 중복 계산 제거
'''
import sys
input = sys.stdin.readline
from collections import deque

m, n = map(int, input().split())
board = [list(map(int, input().strip())) for _ in range(n)]

INF = float('inf')
dist = [[INF] * m for _ in range(n)]
dist[0][0] = 0

def bfs():
    q = deque()
    q.append((0, 0))
    while q:
        ti, tj = q.popleft()
        for si, sj in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            ni, nj = ti + si, tj + sj
            if 0 <= ni < n and 0 <= nj < m:
                new_cost = dist[ti][tj] + board[ni][nj]
                if new_cost < dist[ni][nj]:
                    dist[ni][nj] = new_cost
                    if board[ni][nj] == 0:
                        q.appendleft((ni, nj))
                    else:
                        q.append((ni, nj))
    return dist[n-1][m-1]

ans = bfs()

print(ans)