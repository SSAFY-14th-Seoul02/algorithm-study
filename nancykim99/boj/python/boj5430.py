'''
BOJ5430 : AC (G5)

해결 방법 : 
양쪽에서 접근해야 하기에, deque를 자료구조로 가져가기
중간에 deque이 비어 indexerror가 날 경우를 대비해, error라는 플래그 생성
확인하면서 ans까지 진행함
'''
import sys
input = sys.stdin.readline
from collections import deque

tc = int(input())

for _ in range(tc):
    command = input().strip()
    n = int(input())
    arr = input().strip()
    if arr == "[]":
        arr = deque()
    else:
        arr = deque(arr[1:-1].split(","))
    arr = deque(arr)
    start = 0
    error = 0
    for i in range(len(command)):
        if command[i] == "R":
            if start == 0:
                start = 1
            else:
                start = 0
        if command[i] == "D":
            if not arr:
                error = 1
                break
            if start == 0:
                arr.popleft()
            else:
                arr.pop()
    if error:
        print("error")
    else:
        if start == 1:
            arr.reverse()
        print("[" + ",".join(arr) + "]")