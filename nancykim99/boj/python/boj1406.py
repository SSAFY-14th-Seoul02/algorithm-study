'''
BOJ1406 : 에디터 (S2)

해결 방법 : 
list를 2개를 만들어, 커서 앞 뒤라고 생각하고 pop 및 append 진행
커서 뒤에 있는 건 거꾸로 되어 있기에 reverse()
'''

import sys
input = sys.stdin.readline

arr = list(input().rstrip())
n = int(input())
arr_r = []

for i in range(n):
    line = input().split()
    if line[0] == "L":
        if not arr:
            continue
        arr_r.append(arr.pop())
    if line[0] == "D":
        if not arr_r:
            continue
        arr.append(arr_r.pop())
    if line[0] == "B":
        if not arr:
           continue
        arr.pop()
    if line[0] == "P":
        arr.append(line[1])

print(''.join(arr + arr_r[::-1]))