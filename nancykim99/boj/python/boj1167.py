'''
BOJ1167 : 트리의 지름 (G2)

해결 방법 : 
트리를 전체로 입력 받아서 e, w로 각 시작 노드에 맞게 넣고, -1은 제거하기
dfs로 가중치를 추가하면서 한 번 돌리고, 더 먼 노드를 찾기 위해 dfs를 한 번 더 돌리기
트리의 각 끝 점이 첫 dfs를 돌렸을 때 안 나올 수 있기 때문

메모 : 
현재 시간복잡도 : O(V) / 공간복잡도 : O(V)
    노드 수 V = 최대 100,000
    간선 수 E = V - 1 (트리 성질)
    DFS 2회 수행 = O(V + E) * 2 = O(V)
    각 노드 정확히 1번만 방문 (visited == -1 체크)
    스택 최대 깊이 = O(V) (일자 트리 최악의 경우)
    defaultdict 탐색 = 매 루프마다 hash 탐색 발생
    visited = [-1] * (v+1) = DFS마다 O(V) 초기화 * 2회
    tree = defaultdict(list) = 간선 입력마다 동적 리스트 생성

최적화 방법 :
    1. defaultdict(list) → [[] for _ in range(v+1)] 로 변경
       → hash 탐색 제거, 인덱스 직접 접근으로 단축
       → 메모리 한 번에 할당, 동적 리스트 생성 제거
    2. visited = [-1] * (v+1) → 재사용 가능하도록 함수 밖 선언 후 memset 방식으로 초기화
       → DFS 2회마다 새 리스트 생성 제거
    3. stack = [(start, 0)] 선언과 동시에 초기화
       → list() + append() 2번 호출 → 1번으로 단축
    4. max(visited), visited.index(max_dist) 2번 순회
       → enumerate로 1번 순회로 단축
       → O(2V) → O(V)
'''
import sys
input = sys.stdin.readline

from collections import defaultdict

# 트리의 정점의 개수
v = int(input())
tree = defaultdict(list)

for _ in range(v):
    # 정점 번호 및 거리 입력받기
    line = list(map(int, input().split()))
    s = line[0]
    i = 1
    while line[i] != -1:
        e, w = line[i], line[i + 1]
        tree[s].append((e, w))
        i += 2

# dfs로 가장 거리 찾기
def find_longest(start):
    visited = [-1] * (v + 1)
    stack = [(start, 0)]
    while stack:
        node, dist = stack.pop()
        if visited[node] == -1:
            visited[node] = dist
            for e, w in tree[node]:
                if visited[e] == -1:
                    stack.append((e, dist + w))
    
    max_dist = max(visited)
    max_node = visited.index(max_dist)
    return max_node, max_dist

first_node, first_ans = find_longest(1)
ans_node, ans = find_longest(first_node)
print(ans)