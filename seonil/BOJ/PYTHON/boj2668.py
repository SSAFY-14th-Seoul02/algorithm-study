"""
BOJ2668. 숫자고르기

[문제]
세로 두 줄, 가로로 N개의 칸으로 이루어진 표가 있다.
첫째 줄의 각 칸에는 정수 1, 2, …, N이 차례대로 들어 있고 둘째 줄의 각 칸에는 1이상 N이하인 정수가 들어 있다.
첫째 줄에서 숫자를 적절히 뽑으면, 그 뽑힌 정수들이 이루는 집합과, 뽑힌 정수들의 바로 밑의 둘째 줄에 들어있는 정수들이 이루는 집합이 일치한다. 이러한 조건을 만족시키도록 정수들을 뽑되, 최대로 많이 뽑는 방법을 찾는 프로그램을 작성하시오.
예를 들어, N=7인 경우 아래와 같이 표가 주어졌다고 하자.


이 경우에는 첫째 줄에서 1, 3, 5를 뽑는 것이 답이다. 첫째 줄의 1, 3, 5밑에는 각각 3, 1, 5가 있으며 두 집합은 일치한다. 이때 집합의 크기는 3이다.
만약 첫째 줄에서 1과 3을 뽑으면, 이들 바로 밑에는 정수 3과 1이 있으므로 두 집합이 일치한다. 그러나, 이 경우에 뽑힌 정수의 개수는 최대가 아니므로 답이 될 수 없다.

[입력]
첫째 줄에는 N(1≤N≤100)을 나타내는 정수 하나가 주어진다.
그 다음 줄부터는 표의 둘째 줄에 들어가는 정수들이 순서대로 한 줄에 하나씩 입력된다.

[출력]
첫째 줄에 뽑힌 정수들의 개수를 출력하고, 그 다음 줄부터는 뽑힌 정수들을 작은 수부터 큰 수의 순서로 한 줄에 하나씩 출력한다.
"""

from collections import deque

import sys
input = lambda: sys.stdin.readline().rstrip()

# DFS로 사이클을 형성하는 노드들만 nums에 추가하는 함수
def dfs(node, depth, first, second):

    global nums

    # 이미 방문한 노드를 다시 방문했다면, 사이클을 완성했는지 체크
    if visited[node]:
        # 첫째 줄에서 고른 집합과 둘째 줄에서 고른 집합의 일치 여부 체크
        # 만약 문제 조건을 만족(사이클 형성)했다면,
        if first == second:
            # 해당 사이클에 포함된 모든 숫자를 정답 후보에 포함
            for each in first:
                nums.add(each)
        return
    # 방문하지 않은 노드라면:
    # 현재 노드를 방문 처리
    visited[node] = True
    # 현재 노드 번호를 첫째 줄에, 다음 노드 번호를 둘째 줄에 추가
    first.add(node)
    second.add(table[node])
    # 다음 노드로 이동
    dfs(table[node], depth + 1, first, second)
    # 백트래킹: 다른 시작점 탐색을 위해 방문 해제
    visited[node] = False

# main
N = int(input())

# 입력: table[i] = i번 칸의 둘째 줄에 적힌 숫자
table = [0] * (N + 1)
for i in range(1, N + 1):
    table[i] = int(input())

# DFS 방문 체크용
visited = [False] * (N + 1)

# 최종적으로 뽑을 숫자들의 집합
nums = set()

# 모든 숫자를 시작점으로 DFS 시도
for i in range(1, N + 1):
    if not visited[i]:
        first = set()
        second = set()
        dfs(i, 0, first, second)

# 출력 조건에 맞게 정렬
nums = sorted(list(nums))
print(len(nums))
for i in range(len(nums)):
    print(nums[i])