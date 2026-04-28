'''
PGM12987 : 숫자 게임 (LV3)

해결 방법 : 
B와 A의 최대를 비교하고, 만약 A가 더 클 경우, A의 최댓값을 B의 최솟값과 버림으로써 최대 승점 확보
정렬 및 그리지로 해결
'''
from collections import deque
def solution(A, B):
    A.sort()
    B.sort()
    A = deque(A)
    B = deque(B)
    ans = 0
    while B:
        if B[-1] > A[-1]:
            ans += 1
            A.pop()
            B.pop()
        else:
            A.pop()
            B.popleft()
    return ans