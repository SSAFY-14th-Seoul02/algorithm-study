'''
BOJ1874 : 스택 수열 (S2)

해결 방법 : 
현재 숫자와 타겟 숫자를 비교하면서 push와 pop을 정함
타겟 숫자까지 push, 타겟과 stack[-1]이 같은 경우 pop, 아닌 경우 NO
'''
import sys
input = sys.stdin.readline

n = int(input())
stack = []
ans = []
current = 1
is_possible = True

for _ in range(n):
    target = int(input())
    
    while current <= target:
        stack.append(current)
        ans.append('+')
        current += 1
    
    if stack[-1] == target:
        stack.pop()
        ans.append('-')
    else:
        is_possible = False
        break

if is_possible:
    print("\n".join(ans))
else:
    print("NO")