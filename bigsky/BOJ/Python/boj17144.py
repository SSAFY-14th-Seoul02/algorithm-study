# BOJ17144: 미세먼지 안녕!
import sys
input = sys.stdin.readline

dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

# 미세먼지 확산 함수: 정상작동 확인 완료
def spread(room):
    temp = [[0] * C for _ in range(R)]
    for r in range(R):
        for c in range(C):
            c_dust = room[r][c]

            if c_dust <= 0:  # 현재 위치에 먼지가 없으면 넘어감
                continue
            
            n_dust = (c_dust // 5)  # 확산될 먼지의 양
            s_cnt = 0  # 확산된 횟수

            for k in range(4):
                nr = r + dr[k]
                nc = c + dc[k]

                if nr < 0 or nr >= R or nc < 0 or nc >= C:  #먼지 확산 방향이 벽
                    continue
                if room[nr][nc] == -1:  # 먼지 확산 방향이 공기청정기
                    continue
                
                temp[nr][nc] += n_dust
                s_cnt += 1
            
            room[r][c] -= (n_dust * s_cnt)
    
    for r in range(R):
        for c in range(C):
            room[r][c] += temp[r][c]

    return room

# 공기청정기 작동 함수
def clean(room):
    # 윗순환
    p1 = puri[0]
    for i in range(p1-1, 0, -1):
        room[i][0] = room[i-1][0]
    for i in range(C-1):
        room[0][i] = room[0][i+1]
    for i in range(0, p1):
        room[i][C-1] = room[i+1][C-1]
    for i in range(C-1, 1, -1):
        room[p1][i] = room[p1][i-1]
    room[p1][1] = 0

    # 아랫순환
    p2 = puri[1]
    for i in range(p2+1, R-1):
        room[i][0] = room[i+1][0]
    for i in range(C-1):
        room[R-1][i] = room[R-1][i+1]
    for i in range(R-1, p2, -1):
        room[i][C-1] = room[i-1][C-1]
    for i in range(C-1, 1, -1):
        room[p2][i] = room[p2][i-1]
    room[p2][1] = 0
    
    return room

# 맵 크기(R * C) / T: T초가 지난 뒤의 미세먼지 양을 구해야 함
R, C, T = map(int, input().split())

# 초기화
room = [list(map(int, input().split())) for _ in range(R)]

# 공기청정기 행저장
puri = []
for i in range(R):
    if room[i][0] == -1:
        puri.append(i)
        if len(puri) == 2:
            break

# T초 동안 시뮬레이션
for _ in range(T):
    room = clean(spread(room))

result = 0
for i in range(R):
    for j in range(C):
        dust = room[i][j]
        if dust > 0:
            result += dust

print(result)
