'''
BOJ2792. 보석상자 (S1)

시도 1 : 
1. 색을 많은거 순서대로 줄 세우기 -> RYGOBRYGORYGORYGORYRYRY
2. 줄 세운 색을 순서대로 사람들에게 배분하기 <- 한 사람은 같은 색만 받을 수 있음

시도 2:
1. 어차피 한 사람은 하나의 색 이상 가질 수 없음 -> 1~10**9로 한 사람이 가질 수 있는 최대수를 정하기 <- 이분탐색으로 탐색해나가기
2. (한 색의 개수 + 한 사람이 가질 수 있는 최대 수 - 1) // 한 사람이 가질 수 있는 최대 수 로 각 색 별로 몇 명의 사람이 필요할지 구하기
3. 모든 색에서 필요한 사람의 수를 더하기
'''

child, color_num = map(int, input().split())
colors = []

for _ in range(color_num):
    a = int(input())
    colors.append(a)

def find_min_people(x):
    total_people = 0 
    for i in colors:
        total_people += (i + x - 1) // x
    return total_people <= child

start = 1
end = max(colors)

ans = 0
while start <= end:
    mid = (start + end) // 2
    if find_min_people(mid):
        ans = mid
        end = mid - 1
    else:
        start = mid + 1
    
print(ans)

