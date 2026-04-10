"""
BOJ9935. 문자열 폭발

[문제]
상근이는 문자열에 폭발 문자열을 심어 놓았다. 폭발 문자열이 폭발하면 그 문자는 문자열에서 사라지며, 남은 문자열은 합쳐지게 된다.

폭발은 다음과 같은 과정으로 진행된다.

* 문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다. 남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
* 새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
* 폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.

상근이는 모든 폭발이 끝난 후에 어떤 문자열이 남는지 구해보려고 한다. 남아있는 문자가 없는 경우가 있다. 이때는 "FRULA"를 출력한다.
폭발 문자열은 같은 문자를 두 개 이상 포함하지 않는다.

[입력]
첫째 줄에 문자열이 주어진다. 문자열의 길이는 1보다 크거나 같고, 1,000,000보다 작거나 같다.
둘째 줄에 폭발 문자열이 주어진다. 길이는 1보다 크거나 같고, 36보다 작거나 같다.
두 문자열은 모두 알파벳 소문자와 대문자, 숫자 0, 1, ..., 9로만 이루어져 있다.

[출력]
첫째 줄에 모든 폭발이 끝난 후 남은 문자열을 출력한다.
"""

import sys
input = lambda: sys.stdin.readline().rstrip()

# 폭발이 일어난 후 결과 문자열을 반환하는 함수
def explosion(s, explosion_str):
    stack = []
    for ch in s:
        stack.append(ch)

        # 마지막 문자가 폭발 문자열의 마지막 문자와 같고, 스택의 길이가 폭발 문자열 길이보다 길면
        if ch == explosion_str[-1] and len(stack) >= len(explosion_str):
            # 스택의 끝부분 문자열이 폭발 문자열과 같은지 확인
            if ''.join(stack[-len(explosion_str):]) == explosion_str:
                # 같다면 폭발 문자열 길이만큼 stack에서 제거
                del stack[-len(explosion_str):]
    # 폭발 이후 결과물 출력
    result = ''.join(stack)
    return result if result else "FRULA"

# main
s = input()                 # 문자열 입력
explosion_str = input()     # 폭발 문자열 입력
answer = explosion(s, explosion_str)  # 폭발 과정 진행
print(answer)    # 결과 출력