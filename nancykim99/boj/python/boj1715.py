'''
BOJ1715 : 카드 정렬하기 (G4/D2)

해결 방법 :
항상 작은 카드 2개를 꺼내서 더하기 -> 우선순위큐로 작은 카드 2개 찾기
더한 단계를 다시 합쳐서, 각 단계별 합도 구하기

메모 : 
그리디로 카드 조합을 다 돌면서, 가장 작은 합 찾는 방식으로 진행했으나 -> 메모리 초과
10개만 되도, 3,628,800 조합이 되기 때문
'''
import sys, heapq
from itertools import permutations
input = sys.stdin.readline

n = int(input())
arr = []

for _ in range(n):
    heapq.heappush(arr, int(input()))

arrSum = 0
for i in range(n - 1):
    a = heapq.heappop(arr)
    b = heapq.heappop(arr)
    numSum = a + b 
    heapq.heappush(arr, numSum)
    arrSum += numSum

print(arrSum)