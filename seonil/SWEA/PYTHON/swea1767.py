"""
SWEA1767. 프로세서 연결하기

[문제 링크]
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4suNtaXFEDFAUf

참고)
아래 코드에서 가지치기 조건(1, 2)은 없어도 SWEA 기준으로 PASS가 가능하다.
"""

# 상하좌우 델타 배열
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

# 특정 코어에서 특정 방향으로 전선 연결 가능한지 확인하는 함수
def can_connect(y, x, d):

    # 현재 위치를 시작 위치로 설정
    ny, nx = y, x
    length = 0  # 전선 길이는 0

    while True:

        # 해당 방향(d방향)의 다음 위치로 이동
        ny += dy[d]
        nx += dx[d]

        # 격자를 벗어나면, 가장자리까지 도달했으므로 연결 성공
        if not (0<=ny<N and 0<=nx<N):
            return length
        
        # 이동 경로에 코어 또는 전선이 있다면 연결 불가능
        if processor[ny][nx] != 0:
            return -1
        
        # 전선 길이 증가시키기
        length += 1

# 특정 코어에서부터 d 방향으로 전선을 설치하거나 제거하는 함수
def set_line(y, x, d, val):

    # 현재 위치를 시작 위치로 설정
    ny, nx = y, x

    while True:

        # 해당 방향(d방향)의 다음 위치로 이동
        ny += dy[d]
        nx += dx[d]

        # 가장자리에 도달하면 종료
        if not (0<=ny<N and 0<=nx<N):
            return
        
        # 전선 설치(2) 또는 제거(0)
        processor[ny][nx] = val

# DFS를 이용해 모든 코어 연결 경우의 수를 탐색하는 함수
def dfs(idx, core_cnt, wire_len):

    global max_core, min_wire

    remaining = len(cores) - idx

    # 가지치기 1: 남은 코어를 전부 연결해도 현재 최대보다 작으면 중단
    if core_cnt + remaining < max_core:
        return

    # 가지치기 2: 최대 코어 수가 같아질 수 있는 최선이 현재 max_core와 같고, 전선이 이미 더 길면 중단
    if core_cnt + remaining == max_core and wire_len >= min_wire:
        return

    # 모든 코어에 대해 탐색을 완료한 경우
    if idx == len(cores):

        # 지금까지 최대 코어보다 더 많은 코어를 연결했다면, 최대 코어 개수 및 최소 전선 길이 업데이트
        if core_cnt > max_core:
            max_core = core_cnt
            min_wire = wire_len
        # 지금까지의 최대 코어와 같은 개수의 코어를 연결했다면, 최소 전선 길이인지만 검사하고 갱신
        elif core_cnt == max_core:
            min_wire = min(min_wire, wire_len)
        return
    
    # 현재 탐색할 코어 위치
    y, x = cores[idx]

    # 4방향으로 전선 연결 시도하기
    for d in range(4):

        # 1. 해당 방향으로 연결 가능한지 확인
        length = can_connect(y, x, d)

        # 2. 연결 가능하다면,
        if length >= 0:
            set_line(y, x, d, 2)    # 전선 설치
            dfs(idx + 1, core_cnt + 1, wire_len + length)   # 다음 코어 탐색
            set_line(y, x, d, 0)    # 백트래킹(전선 제거)
    
    # 현재 코어를 연결하지 않는 경우도 탐색
    dfs(idx + 1, core_cnt, wire_len)

# main

T = int(input())    # T: 테스트 케이스 개수

for tc in range(1, T + 1):

    N = int(input())    # N: 격자 크기
    processor = [list(map(int, input().split())) for _ in range(N)] # 프로세서 상태 입력 받기

    # 가장자리가 아닌 코어만 저장하기
    cores = []
    for i in range(N):
        for j in range(N):
            if processor[i][j] == 1 and not (i == 0 or i == N-1 or j == 0 or j == N-1):
                cores.append((i, j))

    # DFS 준비
    max_core = 0            # 최대 연결 코어 수를 0으로 초기화
    min_wire = float('inf') # 최소 전선 길이를 무한대로 초기화

    # DFS 시작
    dfs(0, 0, 0)

    # 모든 코어의 연결 경우의 수 탐색 종료 후 전선 최소 길이가 구하는 답이다!
    # 모든 코어가 가장자리인 경우 (min_wire가 inf인 경우) 답은 0
    ans = 0 if min_wire == float('inf') else min_wire

    # 정답 출력
    print(f'#{tc} {ans}')