'''
BOJ5052 : 전화번호 목록 (G4)

해결 방법 : 
트라이를 딕셔너리로 구현하여, 삽입 도중 _end를 만날 경우와, 이미 저장된 번호 이후로 저장해야 하는 상황을 예외로 잡음
예외 상황이 발생할 경우, False로 인식하여 정상적이지 않은 전화번호 목록으로 판별

메모 : 
현재 시간복잡도 : O(T × N × L) / 공간복잡도 : O(N × L)
    T = 테스트케이스 수
    N = 테스트케이스당 전화번호 수 (최대 10,000)
    L = 전화번호 길이 (최대 10)

    테스트케이스 T번
    └── N개 전화번호 삽입
            └── 각 번호마다 L번 문자 순회
                └── dict 접근 (setdefault, in 연산) : O(1) 해시

    최악 노드 수 = N × L = 100,000개 (공유 prefix 없을 때)
    테스트케이스마다 root = dict() 새로 생성 → GC 수거
    동시에 존재하는 노드 = 한 테스트케이스분만
최적화 방법 :
    1. root = dict() → 전역 배열 [[-1] * 10 for _ in range(MAX_NODES)] 로 변경
    → hash 탐색 제거, 인덱스 직접 접근으로 단축
    → 메모리 한 번에 할당, 테스트케이스마다 동적 dict 생성/GC 제거

    2. ord(ch) - ord('0') 로 문자 → 인덱스 직접 변환
    → '0'→0, '1'→1, ..., '9'→9
    → hash 계산 없이 배열 인덱스 직접 접근

    3. '_end' in curr_dict → is_end[node] 배열로 관리
    → dict 해시 탐색 → 배열 인덱스 직접 접근으로 단축

    4. 테스트케이스마다 전체 배열 초기화 → 사용한 노드만 초기화
    → O(MAX_NODES) → O(node_count) 로 단축
'''
import sys
input = sys.stdin.readline

def make_trie(*words):
    root = dict()
    for word in words:
        curr_dict = root
        for letter in word:
            # 삽입 도중 _end를 만날 경우, 이미 저장된 번호가 삽입 번호의 prefix
            if '_end' in curr_dict:
                return False
            curr_dict = curr_dict.setdefault(letter, {})
        # 삽입을 완료한 후에도 남아 있을 경우, 삽입 완료한 번호가 이미 저장된 번호의 prefix
        if len(curr_dict) > 0:
            return False
        curr_dict['_end'] = '_end'
    return True

test_case = int(input())
for _ in range(test_case):
    n = int(input()) # 전화번호의 수
    phones = [input().strip() for _ in range(n)]
    
    ans = make_trie(*phones)
    if ans == True:
        print("YES")
    else:
        print("NO")