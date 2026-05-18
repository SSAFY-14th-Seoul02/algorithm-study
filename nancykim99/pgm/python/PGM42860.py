'''
PGM42860 : 조이스틱 (L2)

해결 방법 : 
상하와 좌우로 나눠 그리디로 진행.
알파벳은 반으로 나누어 앞이면 거기서부터 인덱싱. 뒤면, 뒤부터 인덱싱.
A가 있는 경우, A를 건너뛰고 다시 돌아서 가는 경우, 그냥 오른쪽으로 가능 경우 비교하기.

메모 : 
현재 시간복잡도 : O(N²) | 공간복잡도 : O(1)
최적화 방법 :
    1. alphabet_half, alphabet_back 리스트 → ord() 사용으로 리스트 제거
       [before] if char in alphabet_half: answer += alphabet_half.index(char)
       [after]  up = ord(char) - ord('A'); answer += min(up, 26 - up)
       → 리스트 in 탐색 O(13) + index() O(13) 제거, O(1)로 단축

    2. 좌우 이동 for+while 중첩 O(N²) → 현재 N≤20이라 문제없으나,
       N이 커질 경우 next_idx를 전처리 배열로 미리 계산하면 O(N)으로 단축
       [before] for i in range(n): next_idx = i+1; while name[next_idx]=='A': next_idx+=1
       [after]  next_arr = [...] 미리 계산 후 for문에서 O(1) 참조
       → 중첩 제거로 O(N²) → O(N)
'''

def solution(name):
    alphabet_half = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M']
    alphabet_back = ['Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N']
    answer = 0
    n = len(name)

    for char in name:
        if char in alphabet_half:
            answer += alphabet_half.index(char)
        elif char in alphabet_back:
            answer += alphabet_back.index(char) + 1

    # 좌우 이동
    move = n - 1
    for i in range(n):
        next_idx = i + 1
        while next_idx < n and name[next_idx] == 'A':
            next_idx += 1
        move = min(move, i * 2 + (n - next_idx))
        move = min(move, (n - next_idx) * 2 + i)

    answer += move
    return answer