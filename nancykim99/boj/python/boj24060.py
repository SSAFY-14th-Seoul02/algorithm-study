'''
BOJ24060 : 알고리즘 수업 - 병합 정렬 1 (S3)

해결 방법 : 
의사코드 그대로 닫힌 구간 [p, r] 방식으로 재귀 병합 정렬 구현
merge 안에서 tmp → arr 복사 시마다 cnt 증가시키고, cnt == K가 되는 순간의 값을 res에 저장
마지막에 res 출력 (-1로 초기화해서 K번째가 없으면 자동으로 -1 출력)
'''

import sys
input = sys.stdin.readline

def merge(A, p, q, r):
    global cnt, res
    i = p
    j = q + 1
    tmp = []

    while i <= q and j <= r:
        if A[i] <= A[j]:
            tmp.append(A[i])
            i += 1
        else:
            tmp.append(A[j])
            j += 1

    while i <= q:
        tmp.append(A[i])
        i += 1

    while j <= r:
        tmp.append(A[j])
        j += 1

    i = p
    t = 0

    while i <= r:
        A[i] = tmp[t]
        cnt += 1
        if cnt == K:
            res = A[i]
            return
        i += 1
        t += 1

def merge_sort_iterative(A, n):
    stack = []
    stack.append((0, n - 1, False))  
    while stack:
        p, r, is_merge = stack.pop()

        if p >= r:
            continue

        if is_merge:
            q = (p + r) // 2
            merge(A, p, q, r)
            if res != -1:
                return
        else:
            q = (p + r) // 2
            stack.append((p, r, True))       
            stack.append((q + 1, r, False))  
            stack.append((p, q, False))     

N, K = map(int, input().split())
A = list(map(int, input().split()))
cnt = 0
res = -1

merge_sort_iterative(A, N)
print(res)