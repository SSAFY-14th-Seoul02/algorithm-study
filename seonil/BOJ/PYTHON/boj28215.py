"""
BOJ28215. 대피소

[문제]
2차원 평면의 KOI 마을에 N개의 집이 있다. 각 i번째 집의 위치는 (Xi, Yi)이다.
i번째 집과 j번째 집 사이의 거리는 |Xi - Xj| + |Yi - Yj|이다. 즉, 두 집 사이의 거리는 X의 차이와 Y의 차이의 합이다. 예를 들어, (1, 6)에 위치한 집과 (2, 4)에 위치한 집은 (2 - 1) + (6 - 4)인 3만큼 떨어져 있다.

KOI 마을은 재난 발생 시 주민들이 안전하게 대피할 수 있도록 K개의 집에 대피소를 설치할 계획이다. 모든 주민의 안전을 고려하여, 집에서 가장 가까운 대피소로 이동할 때 가장 긴 거리가 최소가 되도록 대피소를 설치할 K개의 집을 선택하고, 그때 대피소와 가장 멀리 떨어진 집과의 거리를 구하려고 한다.
아래는 5개의 집이 각각 (1, 5), (3, 0), (3, 3), (6, 12), (8, 9)에 위치한 마을의 예이다.

이 마을에 2개의 대피소를 설치하려고 한다. 만약 (3, 0)과 (1, 5)에 위치한 집에 대피소를 설치한다면 설치하지 않은 나머지 세 집에서 가까운 대피소까지의 거리가 각각 3, 11, 12이고, 이 중 가장 먼 거리는 12이다.

하지만 (3, 3)와 (6, 12)에 위치한 집에 대피소를 설치하면 가장 가까운 대피소와 가장 멀리 떨어져 있는 집은 (8, 9)에 위치한 집으로, (6, 12)와 5만큼 떨어져 있다. 대피소를 어떻게 설치해도 최대 거리가 5보다 작아지는 경우가 없으므로 5가 구하고자 하는 거리가 된다.

KOI 마을의 집들의 위치와 설치할 대피소의 개수가 주어질 때, 대피소를 설치하는 모든 방법 중 가장 가까운 대피소와 집 사이의 거리 중 가장 큰 값이 가장 작을 때의 거리를 구해라.

[입력]
첫 번째 줄에 N과 K가 공백을 사이에 두고 주어진다.
다음 N개의 줄에는 집의 위치가 주어지는데, 이 중 i (1 ≤ i ≤ N)번째 줄에는 Xi와 Yi가 공백을 사이에 두고 주어진다.

[출력]
첫 번째 줄에 답을 출력한다.

[제한]
주어지는 모든 수는 정수이다.
1 ≤ K ≤ 3
K ≤ N ≤ 50
0 ≤ Xi ≤ 100,000
0 ≤ Yi ≤ 100,000
같은 위치에 집이 여럿 존재하지 않는다. 즉, (X1, Y1), (X2, Y2), ..., (XN, YN)는 서로 다르다.

"""

from itertools import combinations

import sys
input = lambda: sys.stdin.readline().rstrip()

# 맨해튼 거리 계산 함수
def distance(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

# 대피소를 설치하는 모든 방법 중 가장 가까운 대피소와 집 사이의 거리 중 가장 큰 값이 가장 작을 때의 거리를 반환하는 함수
def find_min_dist(locations, N, K):
    result = float('inf')

    # N개의 집 중 K개를 골라 대피소로 선택(모든 경우 탐색)
    for shelters in combinations(locations, K):
        max_dist = 0    # 현재 선택된 대피소 배치에서의 최대 거리
        # 모든 집에 대해 확인
        for loc in locations:
            # 해당 집이 대피소가 아니면
            if loc not in shelters:
                # 이 집에서 가장 가까운 대피소까지의 거리
                min_dist = float('inf')
                # 각 K개의 대피소를 순회하면서
                for i in range(K):
                    x1, y1 = shelters[i]    # 대피소 위치
                    x2, y2 = loc            # 현재 집 위치
                    dist = distance(x1, y1, x2, y2) # 대피소까지의 거리 확인
                    min_dist = min(dist, min_dist)  # 가장 가까운 대피소 거리 갱신
                # 현재 집 기준 가장 가까운 대피소 거리를 max_dist에 저장 후 더 큰 값 들어오면 갱신
                max_dist = max(min_dist, max_dist)
            # 해당 집이 대피소이면 거리 0이므로 건너뜀
            else:
                continue
        # 하나의 대피소 배치에 대해 최대의 거리가 구해졌으므로 이 값이 최소가 되도록 갱신
        result = min(max_dist, result)
    # 결과 출력
    return result

# main

N, K = map(int, input().split())    # N: 집의 개수, K: 설치할 대피소 개수

locations = []
# 집 위치 입력 받기
for _ in range(N):
    a, b = map(int, input().split())
    locations.append((a, b))

# 최소의 최대 거리 계산
min_d = find_min_dist(locations, N, K)

# 결과 출력
print(min_d)