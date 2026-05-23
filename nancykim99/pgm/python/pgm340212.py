'''
PGM340212 : 퍼즐 게임 챌린지 (LV2)

해결 방법 :
이진 탐색으로 빠르게 level을 확인하여, 최솟값 구하기
'''

def solution(diffs, times, limit):
    n = len(diffs)
    
    def check(level):
        time = 0
        for i in range(n):
            if diffs[i] <= level:
                time += times[i]
            else:
                wrong = diffs[i] - level
                time += (times[i] + times[i-1]) * wrong + times[i]
        return time <= limit
    
    lo = 1
    hi = max(diffs)
    
    while lo < hi:
        mid = (lo + hi) // 2
        if check(mid):
            hi = mid 
        else:
            lo = mid + 1
    
    return lo