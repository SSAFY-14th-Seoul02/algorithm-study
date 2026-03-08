"""
Silver II] 숫자판 점프 - 2210

[문제 링크](https://www.acmicpc.net/problem/2210)

### 성능 요약

메모리: 111524 KB, 시간: 128 ms

### 분류

그래프 이론, 브루트포스 알고리즘, 그래프 탐색, 집합과 맵, 깊이 우선 탐색, 격자 그래프

### 제출 일자

2026년 3월 8일 23:17:28

### 문제 설명

<p>5×5 크기의 숫자판이 있다. 각각의 칸에는 숫자(digit, 0부터 9까지)가 적혀 있다. 이 숫자판의 임의의 위치에서 시작해서, 인접해 있는 네 방향으로 다섯 번 이동하면서, 각 칸에 적혀있는 숫자를 차례로 붙이면 6자리의 수가 된다. 이동을 할 때에는 한 번 거쳤던 칸을 다시 거쳐도 되며, 0으로 시작하는 000123과 같은 수로 만들 수 있다.</p>
<p>숫자판이 주어졌을 때, 만들 수 있는 서로 다른 여섯 자리의 수들의 개수를 구하는 프로그램을 작성하시오.</p>

### 입력

 <p>다섯 개의 줄에 다섯 개의 정수로 숫자판이 주어진다.</p>

### 출력

 <p>첫째 줄에 만들 수 있는 수들의 개수를 출력한다.</p>

"""
import sys
input  = lambda :sys.stdin.readline().rstrip()

DIRS = [[1,0],[0,1],[-1,0],[0,-1]]

def is_valid(i, j):
    return 0 <= i < 5 and 0 <= j < 5


def dfs(i, j, cnt, number):
    if cnt == 6:
        result_set.add(number)
        return

    for di, dj in DIRS:
        ni, nj = i + di, j + dj
        if not is_valid(ni, nj):
            continue
        dfs(ni, nj, cnt + 1, number + str(graph[ni][nj]))

graph = [list(input().split()) for _ in range(5)]

result_set = set()
for i in range(5):
    for j in range(5):
        dfs(i, j,1, graph[i][j])


print(len(result_set))