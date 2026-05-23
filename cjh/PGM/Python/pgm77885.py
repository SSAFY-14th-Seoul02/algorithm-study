def solution(numbers):
    res = []

    for num in numbers:
        binary = bin(num)
        if len(binary) <= 3:
            res.append(num + 1)
        elif len(binary) == 4:
            if binary == '0b11':
                res.append(num + 2)
            else:
                res.append(num + 1)
        elif binary[-3:] == '011':
            res.append(num + 2)
        elif binary[-3:] == '111':
            point = 3
            while True:
                point += 1
                if binary[-point] == '0' or binary[-point] == 'b':
                    res.append(num + 2 ** (point - 2))
                    break
        else:
            res.append(num + 1)
    return res