"""
BOJ21939. 문제 추천 시스템 Version 1

[문제]
tony9402는 최근 깃헙에 코딩테스트 대비 문제를 직접 뽑아서 "문제 번호, 난이도"로 정리해놨다.
깃헙을 이용하여 공부하시는 분들을 위해 새로운 기능을 추가해보려고 한다.
만들려고 하는 명령어는 총 3가지가 있다. 아래 표는 각 명령어에 대한 설명이다.

* recommend x
x가 1인 경우 추천 문제 리스트에서 가장 어려운 문제의 번호를 출력한다.
만약 가장 어려운 문제가 여러 개라면 문제 번호가 큰 것으로 출력한다.
x가 -1인 경우 추천 문제 리스트에서 가장 쉬운 문제의 번호를 출력한다.
만약 가장 쉬운 문제가 여러 개라면 문제 번호가 작은 것으로 출력한다.

* add P L
추천 문제 리스트에 난이도가 L인 문제 번호 P를 추가한다. (추천 문제 리스트에 없는 문제 번호 P만 입력으로 주어진다. 이전에 추천 문제 리스트에 있던 문제 번호가 다른 난이도로 다시 들어 올 수 있다.)

* solved P
추천 문제 리스트에서 문제 번호 P를 제거한다. (추천 문제 리스트에 있는 문제 번호 P만 입력으로 주어진다.)

명령어 recommend는 추천 문제 리스트에 문제가 하나 이상 있을 때만 주어진다.
명령어 solved는 추천 문제 리스트에 문제 번호가 하나 이상 있을 때만 주어진다.
위 명령어들을 수행하는 추천 시스템을 만들어보자.

[입력]
첫 번째 줄에 추천 문제 리스트에 있는 문제의 개수 N 가 주어진다.
두 번째 줄부터 N + 1 줄까지 문제 번호 P와 난이도 L가 공백으로 구분되어 주어진다.
N + 2줄은 입력될 명령문의 개수 M이 주어진다.
그 다음줄부터 M개의 위에서 설명한 명령문이 입력된다.

[출력]
recommend 명령이 주어질 때마다 문제 번호를 한 줄씩 출력한다. 최소 한번의 recommend 명령어가 들어온다.
"""

from heapq import heappop, heappush

import sys
input = lambda: sys.stdin.readline().rstrip()

# 문제를 최소힙, 최대힙, 딕셔너리에 추가하는 함수
def add(prob, level):
    # problems 딕셔너리에 현재 문제 상태 저장
    problems[prob] = level
    # 최소힙에 (난이도, 문제번호) 저장
    heappush(min_heap, (level, prob))
    # 최대힙에 (-난이도, -문제번호) 저장 → heapq는 최소힙이므로 음수로 넣어 최대 힙처럼 사용
    heappush(max_heap, (-level, -prob))

# 문제를 추천하는 함수
def recommend(direction):

    # 1. direction = 1 → 가장 어려운 문제 추천
    if direction == 1:
        while max_heap:
            # 최대힙의 top 확인
            lv, pb = max_heap[0]
            # 최대힙에 음수로 저장했으므로 다시 양수로 복원하기
            lv = -lv
            pb = -pb
            # 현재 problems 딕셔너리에 존재하고, 난이도도 일치하면 유효한 문제임
            if pb in problems and problems[pb] == lv:
                print(pb)
                break
            # 위 경우가 아니라면, 이미 solved 되었거나 난이도가 변경된 오래된 데이터임
            else:
                heappop(max_heap)   # 힙에서 제거 (Lazy Deletion)

    # 2. direction = -1 → 가장 쉬운 문제 추천
    elif direction == -1:
        while min_heap:
            # 최소힙의 top 확인
            lv, pb = min_heap[0]
            # 현재 problems 딕셔너리에 존재하고, 난이도도 일치하면 유효한 문제임
            if pb in problems and problems[pb] == lv:
                print(pb)
                break
            # 위 경우가 아니라면, 이미 solved 되었거나 난이도가 변경된 오래된 데이터임
            else:
                heappop(min_heap)

# main
N = int(input())  # 초기 문제 개수

min_heap = []       # 최소 힙: 가장 쉬운 문제 찾기용
max_heap = []       # 최대 힙: 가장 어려운 문제 찾기용
problems = dict()   # 현재 살아있는 문제 상태 관리용 딕셔너리

# 초기 문제 입력
for _ in range(N):
    P, L = map(int, input().split())
    add(P, L)   # 입력 받은 문제를 추가

M = int(input())  # 명령 개수

# M개의 명령 입력 받기
for _ in range(M):
    cmd = input().split()

    # add: 새 문제 추가하기
    if cmd[0] == 'add':
        add(int(cmd[1]), int(cmd[2]))

    # recommend: 추천 요청하기
    elif cmd[0] == 'recommend':
        recommend(int(cmd[1]))

    # solved: 문제 해결 처리하기
    elif cmd[0] == 'solved':
        # 힙에서는 제거하지 않고 딕셔너리에서만 삭제 (lazy deletion)
        problems.pop(int(cmd[1]), None)