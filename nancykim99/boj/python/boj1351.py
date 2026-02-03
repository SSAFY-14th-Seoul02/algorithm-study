'''
BOJ1351 : 무한 수열 (G5)

해결 방법 : 
재귀에 DP로 풀었다.
'''
import sys
input = sys.stdin.readline

n, p, q = map(int, input().split())
dp = {0 : 1}

def recursion(i, p, q):
    if i in dp:
        return dp[i]
    
    i1 = i // p
    i2 = i // q
    
    dp[i] = recursion(i1, p , q) + recursion(i2, p, q)
    return dp[i]

ans = recursion(n, p, q)
print(ans)