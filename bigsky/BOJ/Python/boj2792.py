# BOJ2792(D2): 보석 상자
import sys
input = sys.stdin.readline

def solve():
    N, M = map(int, input().split())
    gems = []
    lo = 1
    hi = 0
    for _ in range(M):
        c = int(input())
        gems.append(c)
        hi = max(hi, c)

    while lo < hi:
        mid = (lo + hi) // 2
        total = 0
        for c in gems:
            total += (c + mid - 1) // mid
            if total > N:
                break
        if total <= N:
            hi = mid
        else:
            lo = mid + 1
        
    print(lo)

solve()
