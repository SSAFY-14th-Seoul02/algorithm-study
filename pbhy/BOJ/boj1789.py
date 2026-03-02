# 1789. 수들의 합
'''
서로 다른 N개의 자연수의 합이 S라고 한다.
S를 알 때, 자연수 N의 최댓값은 얼마일까?

[입력]
첫째 줄에 자연수 S(1 ≤ S ≤ 4,294,967,295)가 주어진다.

[출력]
첫째 줄에 자연수 N의 최댓값을 출력한다.

1부터 n까지의 자연수의 합 s >= (n(n+1))/2
'''
s = int(input())
result = 0
ans = 0
for n in range(1, s + 1):
    result += n
    if result > s:
        ans = n - 1
        break
    ans = n
print(ans)