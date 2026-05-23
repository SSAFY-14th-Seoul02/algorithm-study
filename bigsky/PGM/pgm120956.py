# 옹알이 (1)
def solution(babbling):
    answer = 0

    for i in range(len(babbling)):
        word = babbling[i]
        idx = 0

        flag = True
        while idx < len(word):
            if word[idx:idx + 2] in ["ye", "ma"]:
                idx += 2
            elif word[idx:idx + 3] in ["aya", "woo"]:
                idx += 3
            else:
                flag = False
                break

        if flag: answer += 1

    return answer