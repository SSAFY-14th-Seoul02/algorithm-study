def solution(common):
    if common[1] * 2 == common[0] + common[2]:
        d = common[1] - common[0]
        return common[-1] + d
    else:
        r = common[1] // common[0]
        return common[-1] * r