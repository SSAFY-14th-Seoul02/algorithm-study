import sys
input = sys.stdin.readline

sys.setrecursionlimit(100000)

N, P, Q = map(int, input().split())

memo = {0: 1}

def calc(num):
    if num in memo:
        return memo[num]

    memo[num] = calc(num // P) + calc(num // Q)

    return memo[num]

print(calc(N))