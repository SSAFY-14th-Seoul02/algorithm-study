"""
BOJ20056. 마법사 상어와 파이어볼

[문제]
어른 상어가 마법사가 되었고, 파이어볼을 배웠다.
마법사 상어가 크기가 N×N인 격자에 파이어볼 M개를 발사했다.
가장 처음에 파이어볼은 각자 위치에서 이동을 대기하고 있다. i번 파이어볼의 위치는 (ri, ci), 질량은 mi이고, 방향은 di, 속력은 si이다. 위치 (r, c)는 r행 c열을 의미한다
격자의 행과 열은 1번부터 N번까지 번호가 매겨져 있고, 1번 행은 N번과 연결되어 있고, 1번 열은 N번 열과 연결되어 있다.

파이어볼의 방향은 어떤 칸과 인접한 8개의 칸의 방향을 의미하며, 정수로는 다음과 같다.

7	0	1
6	 	2
5	4	3

마법사 상어가 모든 파이어볼에게 이동을 명령하면 다음이 일들이 일어난다.

1. 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다.
- 이동하는 중에는 같은 칸에 여러 개의 파이어볼이 있을 수도 있다.
2. 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다.
    1. 같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
    2. 파이어볼은 4개의 파이어볼로 나누어진다.
    3. 나누어진 파이어볼의 질량, 속력, 방향은 다음과 같다.
        1. 질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋이다.
        2. 속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋이다.
        3. 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
        4. 질량이 0인 파이어볼은 소멸되어 없어진다.

마법사 상어가 이동을 K번 명령한 후, 남아있는 파이어볼 질량의 합을 구해보자.
"""

from collections import defaultdict

import sys
input = lambda: sys.stdin.readline().rstrip()

# 파이어볼 방향 델타 배열
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, 1, 1, 1, 0, -1, -1, -1]


def move():

    global fireballs

    # 1. 모든 파이어볼이 자신의 방향 d로 속력 s칸만큼 이동
    # 1번 행은 N번과 연결되어 있고, 1번 열은 N번 열과 연결되어 있으므로, 좌표 연산에 모듈러 연산 이용하기
    for ball in fireballs:
        r, c, m, s, d = ball
        nr = ((r - 1 + dy[d] * s) % N) + 1
        nc = ((c - 1 + dx[d] * s) % N) + 1
        after_pos[(nr, nc)].append((m, s, d))   # 이동한 다음 좌표를 key, 정보를 리스트의 value로 저장

    # 2. 이동이 모두 끝난 뒤에 각 좌표마다 파이어볼 검사
    
    new_balls = []  # 새로운 파이어볼 리스트

    for (r, c), balls_info in after_pos.items():    # 각 좌표에 존재하는 파이어볼 정보 조회

        # 만약 해당 좌표에 파이어볼이 1개 뿐이라면, 그대로 새로운 파이어볼 리스트에 추가
        if len(balls_info) == 1:
            new_balls.append((r, c, balls_info[0][0], balls_info[0][1], balls_info[0][2]))
            continue
        
        # 만약 해당 좌표에 파이어볼이 2개 이상 존재한다면:
        else:
            total_m = sum(b[0] for b in balls_info) # 합쳐진 파이어볼 질량의 합
            total_s = sum(b[1] for b in balls_info) # 합쳐진 파이어볼 속력의 합
            cnt = len(balls_info)                   # 합쳐진 파이어볼의 개수

            new_m = total_m // 5    # 나누어진 새로운 파이어볼 질량 =  ⌊(합쳐진 파이어볼 질량의 합)/5⌋
            if new_m == 0:
                continue            # 질량이 0인 파이어볼은 소멸한다.
            new_s = total_s // cnt  # 나누어진 새로운 파이어볼 속력 =  ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋

            # 합쳐지는 파이어볼의 방향 체크
            all_even = all(b[2] % 2 == 0 for b in balls_info)
            all_odd = all(b[2] % 2 == 1 for b in balls_info)

            for i in range(4):
                # 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면,
                if all_even or all_odd:
                    new_balls.append((r, c, new_m, new_s, 2 * i))   # 새로운 파이어볼 방향은 0, 2, 4, 6
                # 아니면
                else:
                    new_balls.append((r, c, new_m, new_s, 2 * i + 1))   # 새로운 파이어볼 방향은 1, 3, 5, 7
    
    # 새로운 파이어볼 리스트로 갱신
    fireballs = new_balls

# main
N, M, K = map(int, input().split()) # N: 격자의 크기, M: 파이어볼 개수, K: 명령 횟수
fireballs = [tuple(map(int, input().split())) for _ in range(M)]    # 파이어볼 정보 저장

# K번 이동 명령 실행
for _ in range(K):
    after_pos = defaultdict(list) # 이동 이후 파이어볼 정보를 저장할 딕셔너리 생성, 기본값: []
    move()  # 이동!

# 이동 이후 남아있는 파이어볼 질량 합 출력
print(sum(fb[2] for fb in fireballs))