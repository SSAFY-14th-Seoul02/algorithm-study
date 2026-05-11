'''
PGM42578 : 의상 (L2)

해결 방법 : 
종류를 in, not in 으로 찾고, 찾은 종류의 숫자 + 1 만큼 곱한 후, -1로 조합 구하기

메모 : 
조합으로 구할 시, 불필요하게 시간복잡도가 늘어남
현재 시간복잡도 : O(N²) / 공간복잡도 : O(N)
    옷 개수 = N
    cloth_type 리스트 탐색 (in, index) = O(N)
    반복문 N번 → N × N = O(N²)
    cloth_num, cloth_type 각각 리스트 저장 = O(N)
최적화 방법 :
    1. list 탐색 → dict 사용 → O(N²) → O(N)
    2. index() 제거 → O(N) 탐색 제거
    3. list 2개 → dict 1개 → 구조 단순화
    4. get() 사용 → 분기 제거
'''

def solution(clothes):
    cloth_type = []
    cloth_num = []
    for i in range(len(clothes)):
        if clothes[i][1] not in cloth_type:
            cloth_type.append(clothes[i][1])
            cloth_num.append(1)
        else:
            a = cloth_type.index(clothes[i][1])
            cloth_num[a] += 1
    ans_plus = 1      
    for i in range(len(cloth_num)):
        ans_plus *= (cloth_num[i] + 1)
    answer = ans_plus - 1
    return answer