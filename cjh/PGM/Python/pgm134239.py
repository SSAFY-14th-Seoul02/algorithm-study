def solution(k, ranges):
    graph = [k]
    n = 0
    while k > 1:
        if k % 2 == 0:
            k //= 2
        else:
            k = k * 3 + 1
        graph.append(k)
        n += 1

    # 정적분
    area = [0]
    for i in range(n):
        area.append(area[-1] + (graph[i] + graph[i + 1]) / 2)

    # 정답
    res = []
    for r in ranges:
        s = r[0]
        e = r[1]

        if e <= 0:
            e = n + e

        if s > e:
            res.append(-1.0)
            continue
        res.append(area[e] - area[s])
    return res