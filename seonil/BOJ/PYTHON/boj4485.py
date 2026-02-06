"""
BOJ4485. 녹색 옷 입은 애가 젤다지?

[문제]
젤다의 전설 게임에서 화폐의 단위는 루피(rupee)다. 그런데 간혹 '도둑루피'라 불리는 검정색 루피도 존재하는데, 이걸 획득하면 오히려 소지한 루피가 감소하게 된다!
젤다의 전설 시리즈의 주인공, 링크는 지금 도둑루피만 가득한 N x N 크기의 동굴의 제일 왼쪽 위에 있다. [0][0]번 칸이기도 하다.
왜 이런 곳에 들어왔냐고 묻는다면 밖에서 사람들이 자꾸 "젤다의 전설에 나오는 녹색 애가 젤다지?"라고 물어봤기 때문이다.
링크가 녹색 옷을 입은 주인공이고 젤다는 그냥 잡혀있는 공주인데, 게임 타이틀에 젤다가 나와있다고 자꾸 사람들이 이렇게 착각하니까 정신병에 걸릴 위기에 놓인 것이다.
하여튼 젤다...아니 링크는 이 동굴의 반대편 출구, 제일 오른쪽 아래 칸인 [N-1][N-1]까지 이동해야 한다.
동굴의 각 칸마다 도둑루피가 있는데, 이 칸을 지나면 해당 도둑루피의 크기만큼 소지금을 잃게 된다. 링크는 잃는 금액을 최소로 하여 동굴 건너편까지 이동해야 하며, 한 번에 상하좌우 인접한 곳으로 1칸씩 이동할 수 있다.

링크가 잃을 수밖에 없는 최소 금액은 얼마일까?

[입력]
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스의 첫째 줄에는 동굴의 크기를 나타내는 정수 N이 주어진다. (2 ≤ N ≤ 125) N = 0인 입력이 주어지면 전체 입력이 종료된다.
이어서 N개의 줄에 걸쳐 동굴의 각 칸에 있는 도둑루피의 크기가 공백으로 구분되어 차례대로 주어진다.
도둑루피의 크기가 k면 이 칸을 지나면 k루피를 잃는다는 뜻이다. 여기서 주어지는 모든 정수는 0 이상 9 이하인 한 자리 수다.

[출력]
각 테스트 케이스마다 한 줄에 걸쳐 정답을 형식에 맞춰서 출력한다. 형식은 예제 출력을 참고하시오.
"""

from heapq import heappop, heappush

import sys
input = lambda: sys.stdin.readline().rstrip()

# 상하좌우 델타 배열
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

# 다익스트라 알고리즘을 사용하여 start부터 goal까지 이동하며 잃는 최소 루피를 계산하는 함수
def dijkstra(start, goal):
    sy, sx = start  # 시작 좌표: (sy, sx)

    # 우선순위 큐: (현재까지 누적 비용, y좌표, x좌표)
    # 시작 칸도 지나가야 하므로, 시작 비용은 matrix[0][0]
    pq = [(matrix[sy][sx], sy, sx)]

    # min_costs[y][x] : (y, x) 칸까지 도달하는 최소 루피 손실
    min_costs = [[INF] * N for _ in range(N)]
    min_costs[sy][sx] = matrix[sy][sx]

    while pq:
        # 지금까지 비용이 가장 작은 경로를 꺼냄
        cur_cost, cur_y, cur_x = heappop(pq)

        # 이미 더 적은 비용으로 방문한 적이 있다면 스킵
        if min_costs[cur_y][cur_x] < cur_cost:
            continue

        # 현재 위치에서 상하좌우로 이동 시도
        for dir in range(4):
            ny, nx = cur_y + dy[dir], cur_x + dx[dir]
            # 동굴 범위 안에 있는 경우:
            if 0<=ny<N and 0<=nx<N:
                # 다음 칸으로 이동하면 그 칸의 도둑루피만큼 추가 손실
                new_cost = cur_cost + matrix[ny][nx]
                # 이미 더 적은 비용으로 도달 가능하면 갱신 X
                if min_costs[ny][nx] <= new_cost:
                    continue
                # 최소 비용 갱신
                min_costs[ny][nx] = new_cost
                # 우선순위 큐에 새로운 상태 삽입
                heappush(pq, (new_cost, ny, nx))
    
    # 도착 지점의 최소 비용 반환
    gy, gx = goal
    return min_costs[gy][gx]


# main
INF = int(21e8)
tc = 0

while True:

    # 동굴의 크기 N 입력 받기
    N = int(input())

    # 만약 N = 0 입력이 주어지면 전체 입력 종료
    if N == 0:
        break

    else:
        tc += 1 # 테스트 케이스 번호

        # 동굴 정보 (각 칸의 도둑루피 정보) 입력 받기
        matrix = [list(map(int, input().split())) for _ in range(N)]

        # (0,0) → (N-1,N-1) 최소 비용 계산
        min_cost = dijkstra((0, 0), (N - 1, N - 1))

        # 문제에서 요구하는 출력 형식으로 최소비용 출력
        print(f'Problem {tc}: {min_cost}')