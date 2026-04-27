from collections import deque


def solution(queue1, queue2):
    queue1 = deque(queue1)
    queue2 = deque(queue2)
    sum_1 = sum(queue1)
    sum_2 = sum(queue2)

    cnt = 0
    while True:
        if cnt == 1000000:
            return -1

        if sum_1 == sum_2:
            return cnt

        if sum_1 > sum_2:
            temp = queue1.popleft()
            queue2.append(temp)

            sum_1 -= temp
            sum_2 += temp

        elif sum_1 < sum_2:
            temp = queue2.popleft()
            queue1.append(temp)

            sum_2 -= temp
            sum_1 += temp

        cnt += 1