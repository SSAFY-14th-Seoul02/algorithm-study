def solution(targets):
    targets.sort(key=lambda x: (x[0], x[1]))
    start = -1
    end = -1

    cnt = 0
    for target in targets:
        if target[1] < end:
            end = target[1]
        elif end <= target[0]:
            end = target[1]
            cnt += 1
    return cnt