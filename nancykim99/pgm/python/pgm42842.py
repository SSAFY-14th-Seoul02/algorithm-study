'''
PGM42842 : 카펫 (L2)

해결 방법 : 
그냥 전체를 다 돌았다...

메모 : 
'''

def solution(brown, yellow):
    total = brown // 2 + 2 
    for h in range(3, total // 2 + 1):
        w = total - h
        if (w - 2) * (h - 2) == yellow:
            return [w, h]