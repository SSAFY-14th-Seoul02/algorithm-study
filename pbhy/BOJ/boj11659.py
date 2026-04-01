# 11659. 구간 합 구하기 4
'''
수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다. 둘째 줄에는 N개의 수가 주어진다. 수는 1,000보다 작거나 같은 자연수이다. 셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.

[출력]
총 M개의 줄에 입력으로 주어진 i번째 수부터 j번째 수까지 합을 출력한다.

누적합 배열 미리 만들고 배열에 숫자 저장
어차피 인덱스는 +1이니까 누적합에서도 처음은 0으로 해도 그거 빼면 똑같아짐
'''
n, m = map(int, input().split())
arr = list(map(int, input().split()))
result = [0] * (n + 1)
for k in range(1, n+1):
    result[k] = result[k-1] + arr[k-1]
for _ in range(m):
    i, j = map(int, input().split())
    print(result[j] - result[i-1])