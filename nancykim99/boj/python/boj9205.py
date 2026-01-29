'''
BOJ9205 : 맥주 마시면서 걸어가기 (G5)

해결 방법 : 
1번째 : a, b
2번째 : x, y
두 좌표 사이의 거리 : (x - a) + (y - b)
시도 1 : 그냥 구현. 순서대로 모든 편의점 들리기 -> 3% (공개 테케만 맞음)
시도 2 : + 거리가 음수가 나올 수 있기에 절댓값으로 계산 -> 동일 결과
시도 3 : bfs로 가능한 좌표 다 돌다가, 페스티벌을 만나는 경우 True를 반환. 끝까지 못 만나면 False -> 메모리 초과
시도 4 : 좌표를 다 도는 것이 아닌, 인덱싱으로 돌면서 처리 -> 해결!

메모 : 
시간 추가적으로 줄일 수 있는 방법
1. for 문 안에 들어온 편의점 인덱스 중 방문한 인덱스를 지워버리는 등으로 관리하기
2. ti, tj를 꺼내자마자 fx, fy 거리를 따로 체크하지 않고, for 문 안에서 처리하기
3. 그래프 인접 리스트 미리 만들기 : 모든 장소 사이 거리 중 1000 이하인 장소만 모아서 인접 리스트 만들기 -> 페스티벌에 도착하면 가능
'''
from collections import deque

t = int(input()) # test case

def bfs():
    q = deque()
    q.append((hx, hy))
    visited = [0] * (n + 1)
    while q:
        ti, tj = q.popleft()
        for i in range(n + 1):
            if not visited[i]:
                ni, nj = cs[i]
                if abs(ti - fx) + abs(tj - fy) <= 1000:
                    return "happy"
                if abs(ti - ni) + abs(tj - nj) <= 1000:
                    visited[i] = True
                    q.append((ni, nj))
    return "sad"
            

for _ in range(t):
    cs = []
    n = int(input()) # 편의점
    hx, hy = map(int, input().split())
    for i in range(n):
        c, s = map(int, input().split())
        cs.append([c, s])
    fx, fy = map(int, input().split())
    cs.append([fx, fy])
    print(bfs())