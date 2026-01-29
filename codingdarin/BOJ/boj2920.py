# boj 2920. 음계 (D1 / B2)

arr = list(map(int, input().split()))
ans = 'mixed'

if arr == list(range(1, 9)):
    ans = 'ascending'
elif arr == list(range(8, 0, -1)):
    ans = 'descending'

print(ans)