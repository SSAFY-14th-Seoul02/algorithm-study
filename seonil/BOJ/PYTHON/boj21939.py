"""
BOJ21939. 문제 추천 시스템 Version 1

[문제]
tony9402는 최근 깃헙에 코딩테스트 대비 문제를 직접 뽑아서 "문제 번호, 난이도"로 정리해놨다.
깃헙을 이용하여 공부하시는 분들을 위해 새로운 기능을 추가해보려고 한다.
만들려고 하는 명령어는 총 3가지가 있다. 아래 표는 각 명령어에 대한 설명이다.

recommend x

x가 1인 경우 추천 문제 리스트에서 가장 어려운 문제의 번호를 출력한다.
만약 가장 어려운 문제가 여러 개라면 문제 번호가 큰 것으로 출력한다.

x가 -1인 경우 추천 문제 리스트에서 가장 쉬운 문제의 번호를 출력한다.
만약 가장 쉬운 문제가 여러 개라면 문제 번호가 작은 것으로 출력한다.

add P L
추천 문제 리스트에 난이도가 L인 문제 번호 P를 추가한다. (추천 문제 리스트에 없는 문제 번호 P만 입력으로 주어진다. 이전에 추천 문제 리스트에 있던 문제 번호가 다른 난이도로 다시 들어 올 수 있다.)

solved P
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

# 문제를 추가하는 함수
def add(prob, level):
    # 1. problems 딕셔너리에 현재 문제 상태 저장
    problems[prob] = level
    # 2. 최소힙에 (난이도, 문제번호) 저장
    heappush(min_heap, (level, prob))
    # 3. 최대힙에 (-난이도, -문제번호) 저장
    heappush(max_heap, (-level, -prob))

# 문제를 추천하는 함수
def recommend(direction):

    # direction == 1  → 가장 어려운 문제 추천
    if direction == 1:
        # 힙의 top이 실제로 살아 있는 문제인지 확인
        while max_heap:
            # 최대힙의 top 꺼내고, (난이도, 문제번호)를 음수로 저장했으므로 다시 양수로 복원
            lv, pb = max_heap[0]
            lv = -lv
            pb = -pb
            # 힙의 top이 아직 존재하고, 난이도도 일치하면 유효한 문제이므로 문제번호 출력하기
            if pb in problems and problems[pb] == lv:
                print(pb)
                break
            # 위의 경우가 아니면, 이미 solved 되었거나 오래된 데이터이므로 힙에서 제거
            else:
                heappop(max_heap)

    # direction == -1 → 가장 쉬운 문제 추천
    elif direction == -1:
        # 힙의 top이 실제로 살아 있는 문제인지 확인
        while min_heap:
            # 최소힙의 top 꺼내기
            lv, pb = min_heap[0]
            # 힙의 top이 아직 존재하고, 난이도도 일치하면 유효한 문제이므로 문제번호 출력하기
            if pb in problems and problems[pb] == lv:
                print(pb)
                break
            # 위의 경우가 아니면, 이미 solved 되었거나 오래된 데이터이므로 힙에서 제거
            else:
                heappop(min_heap)

# main
N = int(input())    # N: 문제의 개수
min_heap = []       # 최소힙: 가장 쉬운 문제 찾기용
max_heap = []       # 최대힙: 가장 어려운 문제 찾기용
problems = dict()   # 현재 살아 있는 문제 상태 관리용 딕셔너리

# N개의 초기 문제 입력 받기
for _ in range(N):
    P, L = map(int, input().split())
    add(P, L)   # add 함수로 추가

M = int(input())    # M: 명령 개수

for _ in range(M):
    cmd = tuple(input().split())
    # 문제 추가 명령
    if cmd[0] == 'add':
        add(int(cmd[1]), int(cmd[2]))
    # 추천 요청
    elif cmd[0] == 'recommend':
        recommend(int(cmd[1]))
    # 문제 해결 처리
    elif cmd[0] == 'solved':
        # 힙에서는 제거하지 않고 딕셔너리에서만 삭제(lazy deletion)
        problems.pop(int(cmd[1]), None)