def solution(places):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    res = []
    for place in places:
        status = 1
        for i in range(5):
            if not status:
                break
            for j in range(5):
                if place[i][j] == 'P':
                    # 검사해서 status = 0
                    for p in range(4):
                        i_1 = i + dy[p]
                        j_1 = j + dx[p]
                        i_2 = i + dy[p] * 2
                        j_2 = j + dx[p] * 2

                        if 0 <= i_1 < 5 and 0 <= j_1 < 5 and place[i_1][j_1] == 'P':
                            status = 0
                            break
                        if 0 <= i_2 < 5 and 0 <= j_2 < 5 and place[i_2][j_2] == 'P' and place[i_1][j_1] != 'X':
                            status = 0
                            break

                    if (i - 1 >= 0 and j - 1 >= 0) and place[i - 1][j - 1] == 'P':
                        if place[i - 1][j] != 'X' or place[i][j - 1] != 'X':
                            status = 0
                            break
                    if (i - 1 >= 0 and j + 1 < 5) and place[i - 1][j + 1] == 'P':
                        if place[i - 1][j] != 'X' or place[i][j + 1] != 'X':
                            status = 0
                            break
                    if (i + 1 < 5 and j - 1 >= 0) and place[i + 1][j - 1] == 'P':
                        if place[i + 1][j] != 'X' or place[i][j - 1] != 'X':
                            status = 0
                            break
                    if (i + 1 < 0 and j + 1 < 5) and place[i + 1][j + 1] == 'P':
                        if place[i + 1][j] != 'X' or place[i][j + 1] != 'X':
                            status = 0
                            break

        res.append(status)
    return res