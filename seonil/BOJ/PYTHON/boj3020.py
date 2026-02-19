"""
BOJ3020. 개똥벌레

[문제]
개똥벌레 한 마리가 장애물(석순과 종유석)로 가득찬 동굴에 들어갔다. 동굴의 길이는 N미터이고, 높이는 H미터이다. (N은 짝수) 첫 번째 장애물은 항상 석순이고, 그 다음에는 종유석과 석순이 번갈아가면서 등장한다.
아래 그림은 길이가 14미터이고 높이가 5미터인 동굴이다. (예제 그림)



이 개똥벌레는 장애물을 피하지 않는다. 자신이 지나갈 구간을 정한 다음 일직선으로 지나가면서 만나는 모든 장애물을 파괴한다.
위의 그림에서 4번째 구간으로 개똥벌레가 날아간다면 파괴해야하는 장애물의 수는 총 여덟개이다. (4번째 구간은 길이가 3인 석순과 길이가 4인 석순의 중간지점을 말한다)



하지만, 첫 번째 구간이나 다섯 번째 구간으로 날아간다면 개똥벌레는 장애물 일곱개만 파괴하면 된다.
동굴의 크기와 높이, 모든 장애물의 크기가 주어진다. 이때, 개똥벌레가 파괴해야하는 장애물의 최솟값과 그러한 구간이 총 몇 개 있는지 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 N과 H가 주어진다. N은 항상 짝수이다. (2 ≤ N ≤ 200,000, 2 ≤ H ≤ 500,000)
다음 N개 줄에는 장애물의 크기가 순서대로 주어진다. 장애물의 크기는 H보다 작은 양수이다.

[출력]
첫째 줄에 개똥벌레가 파괴해야 하는 장애물의 최솟값과 그러한 구간의 수를 공백으로 구분하여 출력한다.
"""

from collections import defaultdict

import sys
input = lambda: sys.stdin.readline().rstrip()


def calculate_min_breaks(H, stalagmites, stalactites):
    """
    H: 동굴 높이
    stalagmites: 석순 높이별 개수 dict
    stalactites: 종유석 높이별 개수 dict

    return:
        (최소 파괴 개수, 그러한 높이 개수)
    """

    # breaks_diff[i]는 차이 배열
    # "높이 i에서의 충돌 개수"를 만들기 위한 차이 배열
    breaks_diff = [0] * (H + 2)

    # 1️. 석순 처리 (1 ~ height 구간 막음)
    for height, count in stalagmites.items():
        breaks_diff[1] += count
        breaks_diff[height + 1] -= count

    # 2. 종유석 처리 (H-height+1 ~ H 구간 막음)
    for height, count in stalactites.items():
        start = H - height + 1
        breaks_diff[start] += count
        breaks_diff[H + 1] -= count

    # 3️. 누적합 → 실제로 부수는 장애물 개수 배열 생성
    for i in range(1, H + 1):
        breaks_diff[i] += breaks_diff[i - 1]


    # 4️ 최소값과 개수 계산
    min_breaks = min(breaks_diff[1:H + 1])
    count_of_levels = breaks_diff[1:H + 1].count(min_breaks)

    return min_breaks, count_of_levels


# main
N, H = map(int, input().split())    # N: 동굴의 길이, H: 동굴의 높이

stalagmites = defaultdict(int)  # 크기별 석순 카운트 딕셔너리
stalactites = defaultdict(int)  # 크기별 종유석 카운트 딕셔너리

# N줄에 걸처 장애물 정보 입력 받기
for i in range(N):
    size = int(input())   # 장애물 크기
    # 짝수 인덱스이면 석순 카운트
    if i % 2 == 0:
        stalagmites[size] += 1
    # 홀수 인덱스이면 종유석 카운트
    else:
        stalactites[size] += 1

# 최소 파괴해야 하는 장애물 수 및 해당 높이 개수 계산 및 반환
min_breaks, count_of_levels = calculate_min_breaks(H, stalagmites, stalactites)

print(min_breaks, count_of_levels)

"""
<REMIND : 차이배열 + 누적합>

height = 3인 석순, height = 2인 종유석이 있다고 하면:

* h=3 석순 처리 이후
index:  0 1 2 3 4 5 6
value: [0 1 0 0 -1 0 0]

* h = 2 종유석 처리 이후
index:  0 1 2 3 4 5 6
value: [0 1 0 0 0 0 -1]

누적합 하면:
for i in range(1, H+1):
    obs[i] += obs[i-1]

index:  0 1 2 3 4 5 6
value: [0 1 1 1 1 1 -1]

⭢ 시간복잡도 감소
"""