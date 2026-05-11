'''
PGM42746 : 가장 큰 수 (L2)

해결 방법 : 
1000 이하의 수이기에, 각 숫자를 *3해서 정렬하는 방식으로 붙였을 때, 더 클 수를 구하기
그 클 수를 sort하여, 붙였을 때 클 수를 정하기

메모 : 
현재 시간복잡도 : O(N log N) | 공간복잡도 : O(N)
최적화 방법 :
    1. 버블 정렬 O(N²) → sort 사용 O(N log N)
    2. int(str(a)+str(b)) 비교 제거 → 문자열 key 정렬 사용
    3. join(map(str, numbers)) → 이미 문자열이므로 join(numbers)로 단순화
    4. int(answer) 변환 대신 answer[0] == '0'으로 전체 0 처리

계속 버블정렬처럼, 붙이고 더 큰 수가 생기면 그 큰수의 앞 수를 앞으로 정렬했는데, 시간초과가 나서 결국 해결 방법 찾아봤다
희한한 문제다
'''
def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key=lambda x: x * 3, reverse=True)
    answer = ''.join(map(str, numbers))
    if answer[0] == '0':
        return '0'
    return answer