# BOJ7490 : 0 만들기
import sys
input = sys.stdin.readline

def check_zero(ans):
    if eval(ans.replace(' ', '')) == 0:
        print(ans)

def select_operator(depth, ans):
    if depth == N + 1:
        check_zero(ans)
        return

    select_operator(depth+1, ans+' '+str(depth))
    select_operator(depth+1, ans+'+'+str(depth))
    select_operator(depth+1, ans+'-'+str(depth))

T = int(input())
for tc in range(T):
    N = int(input())
    select_operator(2, '1')
    print()
