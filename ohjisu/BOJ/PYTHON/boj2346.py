"""
# [Silver III] 풍선 터뜨리기 - 2346

[문제 링크](https://www.acmicpc.net/problem/2346)

### 성능 요약

메모리: 111312 KB, 시간: 116 ms

### 분류

자료 구조, 덱

### 제출 일자

2026년 4월 6일 21:35:57

### 문제 설명

<p>1번부터 N번까지 N개의 풍선이 원형으로 놓여 있고. i번 풍선의 오른쪽에는 i+1번 풍선이 있고, 왼쪽에는 i-1번 풍선이 있다. 단, 1번 풍선의 왼쪽에 N번 풍선이 있고, N번 풍선의 오른쪽에 1번 풍선이 있다. 각 풍선 안에는 종이가 하나 들어있고, 종이에는 -N보다 크거나 같고, N보다 작거나 같은 정수가 하나 적혀있다. 이 풍선들을 다음과 같은 규칙으로 터뜨린다.</p>

<p>우선, 제일 처음에는 1번 풍선을 터뜨린다. 다음에는 풍선 안에 있는 종이를 꺼내어 그 종이에 적혀있는 값만큼 이동하여 다음 풍선을 터뜨린다. 양수가 적혀 있을 경우에는 오른쪽으로, 음수가 적혀 있을 때는 왼쪽으로 이동한다. 이동할 때에는 이미 터진 풍선은 빼고 이동한다.</p>

<p>예를 들어 다섯 개의 풍선 안에 차례로 3, 2, 1, -3, -1이 적혀 있었다고 하자. 이 경우 3이 적혀 있는 1번 풍선, -3이 적혀 있는 4번 풍선, -1이 적혀 있는 5번 풍선, 1이 적혀 있는 3번 풍선, 2가 적혀 있는 2번 풍선의 순서대로 터지게 된다.</p>

### 입력

 <p>첫째 줄에 자연수 N(1 ≤ N ≤ 1,000)이 주어진다. 다음 줄에는 차례로 각 풍선 안의 종이에 적혀 있는 수가 주어진다. 종이에 0은 적혀있지 않다.</p>

### 출력

 <p>첫째 줄에 터진 풍선의 번호를 차례로 나열한다.</p>

"""
from collections import  deque

N = int(input())
balloons_input = list(map(int, input().split()))
balloons = deque(enumerate(balloons_input, 1)) # enumerate로 (idx, item) 형태 만들어주기
result = []

while balloons:
    idx, target = balloons.popleft() # prev = idx, target = balloons.popleft()

    result.append(idx)

    if not balloons: # popleft() -> result.append 과정 끝난 후 balloons이 없으면 종료
        break

    dir = - 1 if target > 0 else 0 # target이 양수일 땐 보정 필요(prev 포함됨), 음수일 땐 보정 불필요(prev 포함 안됨)
    balloons.rotate(-(target + dir)) # balloons.rotate(양수) -> 오른쪽으로 회전, (음수) -> 왼쪽으로 회전

print(*result)
