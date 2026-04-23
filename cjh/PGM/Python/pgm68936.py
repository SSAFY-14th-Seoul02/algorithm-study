from collections import deque


def solution(arr):
    def quad(i, j, size):
        num = arr[i][j]

        if size == 1 and num:
            return [i, j, size, 1, 0, 1]
        elif size == 1 and not num:
            return [i, j, size, 1, 1, 0]

        is_quad = 1
        for p in range(i, i + size):
            flag = 0
            for q in range(j, j + size):
                if arr[p][q] != num:
                    flag = 1
                    is_quad = 0
                    break
            if flag:
                break
        if is_quad and num == 1:
            return [i, j, size, 1, 0, 1]  # i, j, size, is_quad, cnt_0, cnt_1
        elif is_quad and num == 0:
            return [i, j, size, 1, 1, 0]
        else:
            return [i, j, size, 0, 0, 0]

    res_0 = 0
    res_1 = 0

    q = deque([quad(0, 0, len(arr))])
    while q:
        i, j, size, is_quad, cnt_0, cnt_1 = q.popleft()
        if is_quad:
            res_0 += cnt_0
            res_1 += cnt_1
        else:
            q.append(quad(i, j, size // 2))
            q.append(quad(i + size // 2, j, size // 2))
            q.append(quad(i, j + size // 2, size // 2))
            q.append(quad(i + size // 2, j + size // 2, size // 2))

    return [res_0, res_1]