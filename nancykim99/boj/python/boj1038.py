'''
BOJ1038 : 감소하는 수 (G5)

해결 방법 : 
시도 1 : 개수를 찾고, 숫자를 찾는 방식으로 하려고 했는데, 구현은 됐으나, 원하는 숫자가 안 나옴
시도 2 : 숫자를 미리 만들고, sort해서 인덱스로 찾는 방식으로 진행
'''

n = int(input())
arr = []

def find_num(num):
    arr.append(num)
    last_digit = num % 10
    for i in range(last_digit):
        next_num = num * 10 + i
        find_num(next_num)

for i in range(10):
    find_num(i)

arr.sort()

if n >= len(arr):
    print(-1)
else:
    print(arr[n])