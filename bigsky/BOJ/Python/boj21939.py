# BOJ21939(D2): 문제 추천 시스템 Version 1
import sys
from heapq import heappush, heappop
input = sys.stdin.readline

N = int(input())
min_heap = []
max_heap = []
problems = {}

for _ in range(N):
    P, L = map(int, input().split())
    heappush(min_heap, (L, P))
    heappush(max_heap, (-L, -P))
    problems[P] = L


def recommend(x: int) -> int:
    if x == 1:
        while max_heap:
            l, p = max_heap[0]
            if problems.get(-p) == -l:
                print(-p)
                return
            heappop(max_heap)
    else:
        while min_heap:
            l, p = min_heap[0]
            if problems.get(p) == l:
                print(p)
                return
            heappop(min_heap)

def add(p: int, l: int) -> None:
    heappush(min_heap, (l, p))
    heappush(max_heap, (-l, -p))
    problems[p] = l

def solved(p: int) -> None:
    del problems[p]

M = int(input())
for _ in range(M):
    cmd_input = input()
    if cmd_input[0] == 'r':
        cmd, x = cmd_input.split()
        recommend(int(x))
    elif cmd_input[0] == 'a':
        cmd, p, l = cmd_input.split()
        add(int(p), int(l))
    else:
        cmd, p = cmd_input.split()
        solved(int(p))
