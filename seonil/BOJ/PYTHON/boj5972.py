"""
BOJ5972. 택배 배송

[문제]
농부 현서는 농부 찬홍이에게 택배를 배달해줘야 합니다. 그리고 지금, 갈 준비를 하고 있습니다. 평화롭게 가려면 가는 길에 만나는 모든 소들에게 맛있는 여물을 줘야 합니다. 물론 현서는 구두쇠라서 최소한의 소들을 만나면서 지나가고 싶습니다.
농부 현서에게는 지도가 있습니다. N (1 <= N <= 50,000) 개의 헛간과, 소들의 길인 M (1 <= M <= 50,000) 개의 양방향 길이 그려져 있고, 각각의 길은 C_i (0 <= C_i <= 1,000) 마리의 소가 있습니다.
소들의 길은 두 개의 떨어진 헛간인 A_i 와 B_i (1 <= A_i <= N; 1 <= B_i <= N; A_i != B_i)를 잇습니다. 두 개의 헛간은 하나 이상의 길로 연결되어 있을 수도 있습니다.
농부 현서는 헛간 1에 있고 농부 찬홍이는 헛간 N에 있습니다.

다음 지도를 참고하세요.

농부 현서가 선택할 수 있는 최선의 통로는 1 -> 2 -> 4 -> 5 -> 6 입니다. 왜냐하면 여물의 총합이 1 + 0 + 3 + 1 = 5 이기 때문입니다.
농부 현서의 지도가 주어지고, 지나가는 길에 소를 만나면 줘야할 여물의 비용이 주어질 때 최소 여물은 얼마일까요?
농부 현서는 가는 길의 길이는 고려하지 않습니다.

[입력]
첫째 줄에 N과 M이 공백을 사이에 두고 주어집니다.
둘째 줄부터 M+1번째 줄까지 세 개의 정수 A_i, B_i, C_i가 주어집니다.

[출력]
첫째 줄에 농부 현서가 가져가야 될 최소 여물을 출력합니다.
"""

from heapq import heappop, heappush

import sys
input = lambda: sys.stdin.readline().rstrip()

# 다익스트라 알고리즘을 사용하여 start부터 goal까지 이동할 때 필요한 최소 여물 비용을 반환하는 함수
def dijkstra(start, goal):

    # 우선순위 큐: (현재까지 누적 비용, 현재 위치 헛간)
    pq = [(0, start)]

    # min_costs[i] : start에서 i번 헛간까지의 최소 여물 비용
    min_costs = [INF] * (N + 1)
    min_costs[start] = 0

    while pq:
       # 지금까지 비용이 가장 작은 경로를 꺼냄
        cur_cost, cur_node = heappop(pq)

        # 이미 더 적은 비용으로 방문한 적이 있다면 스킵
        if min_costs[cur_node] < cur_cost:
            continue

        # 현재 노드에서 인접한 노드들으로 이동 시도
        for each in adj_lst[cur_node]:
            edge_cost, next_node = each

            # 다음 노드로 이동하려면 다음 길의 소 마릿수만큼 추가 여물 비용 발생
            new_cost = cur_cost + edge_cost

            # 이미 next_node에 더 적은 비용으로 도달 가능하다면 갱신 X
            if min_costs[next_node] <= new_cost:
                continue

            # 최소 비용 갱신
            min_costs[next_node] = new_cost

            # 우선순위 큐에 새로운 상태 추가
            heappush(pq, (new_cost, next_node))
    
    # 목표 헛간까지의 최소비용 반환
    return min_costs[goal]

# main
INF = 21e8

# 헛간 개수 N, 길 개수 M 입력 받기
N, M = map(int, input().split())

# 인접 리스트 입력 받기
adj_lst = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b, c = map(int, input().split())
    adj_lst[a].append((c, b))
    adj_lst[b].append((c, a))   # 양방향 그래프이므로 양쪽에 모두 추가

# 1번 헛간 → N번 헛간까지 이동하는 데 필요한 최소 여물 비용 계산
min_cost = dijkstra(1, N)
print(min_cost)