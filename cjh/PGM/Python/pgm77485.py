def solution(rows, columns, queries):
    arr = [[columns*i + j + 1 for j in range(columns)] for i in range(rows)]
    
    res = []
    for s_i, s_j, e_i, e_j in queries:
        s_i -= 1
        s_j -= 1
        e_i -= 1
        e_j -= 1
        
        min_value = arr[s_i][s_j]
        temp = arr[s_i][s_j]
        # 아래에서 위 채우기
        for i in range(s_i+1, e_i+1):
            min_value = min(min_value, arr[i][s_j])
            arr[i-1][s_j] = arr[i][s_j]
        # 오른쪽에서 왼쪽 채우기
        for j in range(s_j+1, e_j+1):
            min_value = min(min_value, arr[e_i][j])
            arr[e_i][j-1] = arr[e_i][j]  
        # 위에서 아래 채우기
        for i in range(e_i-1, s_i-1, -1):
            min_value = min(min_value, arr[i][e_j])
            arr[i+1][e_j] = arr[i][e_j]
        # 왼쪽에서 오른쪽 채우기
        for j in range(e_j-1, s_j, -1):
            min_value = min(min_value, arr[s_i][j])
            arr[s_i][j+1] = arr[s_i][j]  
        # 처음값
        arr[s_i][s_j+1] = temp
        
        res.append(min_value)
    return res