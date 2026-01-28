'''
BOJ4485 : 녹색 옷 입은 애가 젤다지? (G4)

해결 방법 : 
다익스트라로 최단거리를 구할 수 있었음
'''
import heapq

def dijkstra(arr):
    # 거리 테이블
    dist = [[float('inf')] * n for _ in range(n)]
    dist[0][0] = arr[0][0]

    pq = [(arr[0][0], 0, 0)]

    while pq:
        d, ti, tj = heapq.heappop(pq)
        if dist[ti][tj] < d: # 만약에 이미 처리가 된 더 짧은 경로라면 무시
            continue
        for si, sj in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            ni, nj = ti + si, tj + sj
            if 0 <= ni < n and 0 <= nj < n:
                new_d = d + arr[ni][nj]
                if new_d < dist[ni][nj]:
                    dist[ni][nj] = new_d
                    heapq.heappush(pq, (new_d, ni, nj))
    
    return dist[n-1][n-1]

cnt = 0
while True:
    n = int(input())
    if n == 0:
        break
    arr = [list(map(int, input().split())) for _ in range(n)]

    ans = dijkstra(arr)
    cnt += 1
    print(f'Problem {cnt}: {ans}')