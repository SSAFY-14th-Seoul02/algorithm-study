'''
BOJ24060 : 알고리즘 수업 - 병합 정렬 3 (G5)

해결 방법 : 
의사코드 그대로 닫힌 구간 [p, r] 방식으로 재귀 병합 정렬 구현
idx로 현재까지 A와 B가 일치하는 마지막 인덱스를 추적
merge 중 idx 이전 구간이 깨지면 즉시 0 출력, idx가 n-1까지 확장되면 즉시 1 출력
초기 상태 A == B도 별도로 체크.
'''

import sys
input = sys.stdin.readline

def merge(l, p, q, r):
    global idx
    tmp = []
    i = p
    j = q + 1

    while i <= q and j <= r:
        if l[i] <= l[j]:
            tmp.append(l[i])
            i += 1
        else:
            tmp.append(l[j])
            j += 1

    while i <= q:
        tmp.append(l[i])
        i += 1

    while j <= r:
        tmp.append(l[j])
        j += 1

    a = p
    b = 0

    while a <= r:
        l[a] = tmp[b]

        if a <= idx and l[a] != lb[a]:
            print(0)
            sys.exit()

        if l[a] == lb[a]:
            for i in range(idx, n):
                if l[i] == lb[i]:
                    idx = i
                else:
                    break
                if i == n - 1:
                    print(1)
                    sys.exit()

        a += 1
        b += 1

def merge_sort(l, p, r):
    if p < r:
        q = (p + r) // 2
        merge_sort(l, p, q)
        merge_sort(l, q + 1, r)
        merge(l, p, q, r)

n = int(input())
l = list(map(int, input().split()))
lb = list(map(int, input().split()))
idx = -1

if l == lb:
    print(1)
    sys.exit()

merge_sort(l, 0, n - 1)
print(0)