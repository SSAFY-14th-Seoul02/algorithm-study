'''
BOJ1931 : 회의실 배정 (G5)

해결 방법 : 
회의 엔딩 시간을 기준으로 정렬하고, 같을 경우 시작 시간을 기준으로 정렬
엔딩 시간을 기준으로 시작 시간이 이전 엔딩 시간보다 크거나 같을 경우, 업데이트 및 cnt += 1로 구하기
'''

import sys
input = sys.stdin.readline

n = int(input())
arr = []

for _ in range(n):
    a, b = map(int, input().split())
    arr.append((b, a))

arr.sort()

cnt = 0
end_time = 0
for i in range(n):
    k, j = arr[i]
    if j >= end_time:
        end_time = k
        cnt += 1

print(cnt)