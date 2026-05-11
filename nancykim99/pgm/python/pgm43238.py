'''
PGM43238 : 입국심사 (L3)

해결 방법 : 
이분 탐색을 통해, n 이상, 미만일 경우를 나누어 mid가 답일때까지 계속 진행하기
이분 탐색으로 탐색 횟수를 줄이기
'''

def solution(n, times):
    right = n * max(times)
    left = 1
    while left <= right:
        mid = (left + right) // 2
        total = 0
        for t in times:
            total += mid // t
        if total >= n:
            answer = mid
            right = mid - 1
        else:
            left = mid + 1
    return answer