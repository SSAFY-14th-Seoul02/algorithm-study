'''
PGM49189 : 가장 먼 노드 (L3)

해결 방법 : 
bfs로 1 돌리면서 가장 먼 노드 구하기 -> 가장 먼 노드와 같을 경우 개수에 추가하기

메모 : 
현재 시간복잡도 : O(N + E) / 공간복잡도 : O(N + E)
    노드 수 = N (최대 20,000)
    간선 수 = E (최대 50,000)

    인접 리스트 구축: edge 배열 한 번 순회 = O(E)
    BFS 탐색:
        각 노드는 deque에 정확히 1번 삽입·삭제 = O(N)
        각 간선은 양방향으로 정확히 2번 확인 = O(2E) = O(E)
        → BFS 전체 = O(N + E)
    최댓값·카운트 순회: visited 배열 한 번 순회 = O(N)
    총합 = O(E) + O(N + E) + O(N) = O(N + E)

    공간:
        c_list (인접 리스트): 노드 N개 + 양방향 간선 2E개 = O(N + E)
        visited 배열: O(N)
        deque: 최악의 경우 모든 노드 동시 삽입 (star graph) = O(N)
        → 합계 = O(N + E)

    최악 케이스: 20,000 + 50,000 = 70,000 연산 → 제한 시간 내 여유롭게 통과

최적화 방법 :
    1. c_list = [[] * (n+1) for ...] → [[] for ...] → 현재 [] * (n+1)은 빈 리스트라 버그 (기능 수정)
    2. for i in range(len(edge)) → for u, v in edge → 파이썬다운 순회로 가독성·속도 개선
    3. for k in range(1, n+1) 카운트 → max·count 내장함수 활용
       → max_d = max(visited[1:]); return visited[1:].count(max_d) → C 레벨 루프로 2-3배 단축
    4. graph[node] 반복 접근 → 지역 변수 바인딩
       → neighbors = c_list[t]; for j in neighbors → LEGB 검색 회피, 미세 최적화
'''
from collections import deque

def solution(n, edge):
    # 인접리스트 만들기
    c_list = [[] * (n + 1) for _ in range(n + 1)]
    for i in range(len(edge)):
        c_list[edge[i][0]].append(edge[i][1])
        c_list[edge[i][1]].append(edge[i][0])
    def bfs(num):
        visited = [0] * (n + 1)
        q = deque()
        q.append(num)
        visited[num] = 1
        while q:
            t = q.popleft()
            for j in c_list[t]:
                if not visited[j]:
                    visited[j] = visited[t] + 1
                    q.append(j)
        flag = 0
        temp = 0
        for k in range(1, n + 1):
            if visited[k] > flag:
                flag = visited[k]
                temp = 1
            elif visited[k] == flag:
                temp += 1
        return temp
    answer = bfs(1)
    return answer