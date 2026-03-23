"""
BOJ16120. PPAP

[문제]
bryan은 PPAP를 좋아한다. bryan은 어떻게 하면 사람들에게 PPAP를 전파할 수 있을까 고민하던 중 PPAP 문자열이라는 것을 고안하게 되었다.
PPAP 문자열은 문자열 P에서 시작하여, 문자열 내의 P를 PPAP로 바꾸는 과정을 반복하여 만들 수 있는 문자열로 정의된다. 정확하게는 다음과 같이 정의된다.

* P는 PPAP 문자열이다.
* PPAP 문자열에서 P 하나를 PPAP로 바꾼 문자열은 PPAP 문자열이다.

예를 들어 PPAP는 PPAP 문자열이다.
또한, PPAP의 두 번째 P를 PPAP로 바꾼 PPPAPAP 역시 PPAP 문자열이다.

문자열이 주어졌을 때, 이 문자열이 PPAP 문자열인지 아닌지를 알려주는 프로그램을 작성하여라.

[입력]
첫 번째 줄에 문자열이 주어진다. 문자열은 대문자 알파벳 P와 A로만 이루어져 있으며, 문자열의 길이는 1 이상 1,000,000 이하이다.

[출력]
첫 번째 줄에 주어진 문자열이 PPAP 문자열이면 PPAP를, 아닌 경우 NP를 출력한다.
"""

import sys
input = lambda: sys.stdin.readline().rstrip()

# PPAP 문자열인지 검사하는 함수
def is_PPAP(s):

    """
    핵심 아이디어: PPAP 문자열의 정의를 뒤집어서 생각하기:
                PPAP 패턴이 나오면 → P로 치환
                최종적으로 문자열이 "P" 하나만 남으면 PPAP 문자열이다!
                → 스택에 문자 쌓으면서 마지막 4개가 PPAP인지 체크해서 줄이기
    """

    stack = []

    # 문자열의 각 문자에 대하여
    for ch in s:

        # 현재 문자를 스택에 추가
        stack.append(ch)

        # 스택의 마지막 4개가 'PPAP'라면
        if len(stack) > 3 and stack[-1] == 'P' and stack[-2] == 'A' and stack[-3] == 'P' and stack[-4] == 'P':
            # 마지막 'P' 하나만 남기고 제거하기
            for _ in range(3):
                stack.pop()
    
    # 모든 문자열 처리 후 최종적으로 스택에 'P'만 남아있으면 PPAP 문자열이므로 True 반환
    if len(stack) == 1 and stack[-1] == 'P':
        return True
    # 아니라면 False 반환
    else:
        return False

# main
s = input() # 문자열 입력 받기
print("PPAP" if is_PPAP(s) else "NP")   # 문자열이 PPAP 문자열이면 'PPAP', 아니라면 'NP' 출력하기