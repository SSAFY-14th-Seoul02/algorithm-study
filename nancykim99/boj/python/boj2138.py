'''
BOJ2138 : 전구와 스위치 (G4)

해결 방법 : 
그리디로 0번째를 클릭 했을 때와 클릭 안 했을때로 나눠서 진행하기
클릭하는 인덱스의 -1를 end와 비교해서 flip 할지 정하기
'''
import sys
input = sys.stdin.readline

n = int(input())
start = list(map(int, input().strip()))
end = list(map(int, input().strip()))

def flip(b, idx):
    for i in range(idx - 1, idx + 2):
        if 0 <= i < n:
            b[i] = 1 - b[i]
            
def click(state, target, cnt):
    s = state[:]
    for i in range(1, n):
        if s[i - 1] != target[i - 1]:
            cnt += 1
            flip(s, i)
    
    if s == target:
        return cnt
    else:
        return float('inf')

# 0번 스위치를 누르지 않는 경우
notclick = click(start, end, 0)

# 0번 스위치를 누르는 경우
clickzero = start[:]
clickzero[0] = 1 - clickzero[0]
if n > 1: 
    clickzero[1] = 1 - clickzero[1]
clickzero_res = click(clickzero, end, 1)

ans = min(notclick, clickzero_res)

if ans == float('inf'):
    print(-1)
else:
    print(ans)