"""
BOJ1717. 집합의 표현

[문제]
초기에 n+1개의 집합 {0}, {1}, {2}, ... , {n}이 있다.
여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.
집합을 표현하는 프로그램을 작성하시오.

[입력]
첫째 줄에 n, m이 주어진다. m은 입력으로 주어지는 연산의 개수이다.
다음 m개의 줄에는 각각의 연산이 주어진다. 합집합은 0 a b의 형태로 입력이 주어진다. 이는 a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다.
두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a b의 형태로 입력이 주어진다. 이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다.

[출력]
1로 시작하는 입력에 대해서 a와 b가 같은 집합에 포함되어 있으면 "YES" 또는 "yes"를, 그렇지 않다면 "NO" 또는 "no"를 한 줄에 하나씩 출력한다.

[제한]
* 1 ≤ n ≤ 1,000,000
* 1 ≤ m ≤ 100,000
* 0 ≤ a, b ≤ n
* a, b는 정수
* a와 b는 같을 수도 있다.
"""

import sys
input = lambda: sys.stdin.readline().rstrip()

# Union-find: 대표 root를 찾는 함수
# 재귀 대신 while문으로 RecursionError 방지
def find_set(x):
    # x가 자기 자신을 부모로 가지면 그것이 집합의 대표
    # 만약 그렇지 않으면, 가장 상위 부모 찾아 올라가기
    while x != parents[x]:
        # 경로 단축
        parents[x] = parents[parents[x]] 
        x = parents[x]
    return x

def union(x, y):
    rx = find_set(x)
    ry = find_set(y)
    if rx == ry:
        return
    elif rx < ry:
        parents[ry] = rx
    else:
        parents[rx] = ry

# x, y가 같은 집합에 속해 있는지 확인하는 함수. find_set 이용
def check_set(x, y):
    rx = find_set(x)
    ry = find_set(y)
    if rx == ry:
        print("YES")    # 같은 집합에 속하면 'YES'
    else:
        print("NO")     # 같은 집합에 속해 있지 않으면 'NO'

# main
n, m  = map(int, input().split()) # n, m 입력 받기
parents = [i for i in range(n + 1)] # 초기 집합 상태
# m개의 연산 처리
for _ in range(m):
    cmd, a, b = map(int, input().split())
    # 0 a b : a와 b에 합집합 연산
    if cmd == 0:
        union(a, b)
    # 1 a b : a와 b가 같은 집합인지 확인
    else:
        check_set(a, b)

"""
기존에 배웠던 find_set을 사용하면 BOJ에서 RecursionError에 걸린다.

def find_set(x):
    if x == parents[x]:
        return x
    parents[x] = find_set(parents[x])
    return parents[x]

* 이유:
재귀 함수 find_set에서,
최악의 경우 트리가 이렇게 생길 수 있음
```
0 <- 1 <- 2 <- 3 <- 4 <- ... <- 1000000
```
위의 경우에서 find_set(1000000)하면 재귀호출 '100만 번' but 파이썬의 기본 재귀 제한 recursionlimit은 1000이므로 터짐!

따라서 아래와 같이 반복문을 사용하여 경로 단축 및 루트 노드를 찾도록 수정했음.
```python
def find_set(x):
    while x != parents[x]:
        parents[x] = parents[parents[x]]  # path halving
        x = parents[x]
    return x
```
"""