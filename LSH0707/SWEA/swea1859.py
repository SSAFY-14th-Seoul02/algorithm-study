# T = int(input())
# for test_case in range(1, T + 1):
#     N = int(input())
#     arr = list(map(int, input().split()))
#     profit = 0
#     for i in range(N): # 1~n 일차 가격
#         max_profit = 0
#         for j in range(i,N):
#             if max_profit < arr[j] - arr[i]:
#                 max_profit = arr[j] - arr[i]

#         profit = profit + max_profit
    
#     print(f'#{test_case} {profit}')  # for문 2개라 n^2 시간초과(gpt)

T = int(input())
for test_case in range(1, T + 1):
    N = int(input())
    arr = list(map(int, input().split()))
    