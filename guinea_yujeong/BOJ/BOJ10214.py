'''
백준 10214번 : Baseball

[문제]
경근이는 수업 과제의 일환으로 연세대학교의 역사를 조사하고 있었다. 
케케묵은 도서관 구석에서 경근이가 발견한 것은 역대 연고전의 야구경기 실황 기록문서였다.
하지만 문서를 가지고 있음에도 불구하고 한 눈에 당시의 경기 승패를 파악하기에는 어려움이 많았는데, 
문서에는 회차별 양 팀 획득 점수만이 적혀져 있기 때문이었다.
경근이는 주어진 방대한 자료를 해석하는것이 귀찮았기 때문에 
절친한 프로그래머 친구인 당신에게 도움을 요청했다.
주어진 실황 기록문서에서 어떤 팀이 이겼는지를 알아내 경근이를 도와주자!

[입력]
첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 100)가 주어진다.
각 테스트 케이스는 한 줄로 이루어져 있으며, 18번의 득점 정보가 공백으로 구분되어 주어진다.
첫 9개의 숫자는 연세대학교의 득점이고, 다음 9개의 숫자는 고려대학교의 득점이다.

[출력]
각각의 케이스마다 한 줄에 연세대가 이겼을 경우 "Yonsei", 
고려대가 이겼을 경우 "Korea", 비겼을 경우 "Draw"를 출력한다.
'''

T = int(input())

for _ in range(T):
    yonsei_score = 0
    korea_score = 0
    
    for _ in range(9):
        y, k = map(int, input().split())
        yonsei_score += y
        korea_score += k
        
    if yonsei_score > korea_score:
        print("Yonsei")
    elif korea_score > yonsei_score:
        print("Korea")
    else:
        print("Draw")