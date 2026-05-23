def solution(dots):
    candis = [(0, 1, 2, 3),
              (0, 2, 1, 3),
              (0, 3, 1, 2)]

    for candi in candis:
        a1, a2 = dots[candi[0]], dots[candi[1]]
        b1, b2 = dots[candi[2]], dots[candi[3]]

        if (a1[0] - a2[0]) * (b1[1] - b2[1]) == (b1[0] - b2[0]) * (a1[1] - a2[1]):
            return 1
    else:
        return 0