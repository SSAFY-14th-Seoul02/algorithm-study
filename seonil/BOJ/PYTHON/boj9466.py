"""
[문제]
이번 가을학기에 '문제 해결' 강의를 신청한 학생들은 텀 프로젝트를 수행해야 한다.
프로젝트 팀원 수에는 제한이 없다. 심지어 모든 학생들이 동일한 팀의 팀원인 경우와 같이 한 팀만 있을 수도 있다.
프로젝트 팀을 구성하기 위해, 모든 학생들은 프로젝트를 함께하고 싶은 학생을 선택해야 한다. (단, 단 한 명만 선택할 수 있다.) 혼자 하고 싶어하는 학생은 자기 자신을 선택하는 것도 가능하다.

학생들이(s1, s2, ..., sr)이라 할 때, r=1이고 s1이 s1을 선택하는 경우나, s1이 s2를 선택하고, s2가 s3를 선택하고,..., sr-1이 sr을 선택하고, sr이 s1을 선택하는 경우에만 한 팀이 될 수 있다.

예를 들어, 한 반에 7명의 학생이 있다고 하자. 학생들을 1번부터 7번으로 표현할 때, 선택의 결과는 다음과 같다.

1	2	3	4	5	6	7
3	1	3	7	3	4	6

위의 결과를 통해 (3)과 (4, 7, 6)이 팀을 이룰 수 있다. 1, 2, 5는 어느 팀에도 속하지 않는다.
주어진 선택의 결과를 보고 어느 프로젝트 팀에도 속하지 않는 학생들의 수를 계산하는 프로그램을 작성하라.

[입력]
첫째 줄에 테스트 케이스의 개수 T가 주어진다.
각 테스트 케이스의 첫 줄에는 학생의 수가 정수 n (2 ≤ n ≤ 100,000)으로 주어진다.
각 테스트 케이스의 둘째 줄에는 선택된 학생들의 번호가 주어진다. (모든 학생들은 1부터 n까지 번호가 부여된다.)

[출력]
각 테스트 케이스마다 한 줄에 출력하고, 각 줄에는 프로젝트 팀에 속하지 못한 학생들의 수를 나타내면 된다.
"""

import sys
input = lambda: sys.stdin.readline().rstrip()

# start 학생부터 시작해서 한 방향으로 계속 따라가면서 사이클 있는지 확인하는 함수
def dfs(start, students, visited, finished):
    cur = start
    path_order = dict() # 이번 탐색에서 방문 순서를 기록하는 딕셔너리 {학생 번호: 방문 순서}
    order = 0
    team_count = 0

    while True:
        # 아직 방문하지 않은 학생이라면:
        if not visited[cur]:
            visited[cur] = True     # 방문 처리
            path_order[cur] = order # 이번 경로에서 몇번째 방문인지 기록
            order += 1
            cur = students[cur]     # 다음 학생으로 이동
        # 이미 방문한 학생이라면:
        else:
            # 방문했는데 finished가 아직 아니라면 사이클이 발생한 것이다
            if not finished[cur]:
                # 사이클 길이 계산: 전체 방문 수 - 사이클 시작 위치  
                team_count += order - path_order[cur]
            break

    # 이번 탐색 경로 모두 처리 완료 표시
    for node in path_order:
        finished[node] = True

    # 사이클 길이 반환
    return team_count


# main
T = int(input())    # T: 테스트 케이스 개수
for _ in range(T):
    n = int(input())    # n: 학생 수
    students = [0] + list(map(int, input().split()))   # 선택된 학생들의 번호 입력 받기

    visited = [False] * (n + 1)     # DFS 검사 했는지
    finished = [False] * (n + 1)    # 경로 계산이 끝났는지

    team_count = 0  # 팀(사이클)에 속한 학생 수

    # 모든 학생을 시작점으로 DFS 시도
    for i in range(1, n + 1):
        # 이미 다른 탐색에서 처리된 학생이면 건너뜀
        if not visited[i]:
            team_count += dfs(i, students, visited, finished)

    # (전체 학생 수) - (팀에 속한 학생 수)를 계산하여 팀에 속하지 못한 학생 수 출력
    print(n - team_count)