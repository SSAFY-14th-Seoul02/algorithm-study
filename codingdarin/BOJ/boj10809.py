# boj 10809. 알파벳 찾기 (D1 / B2)

# print(ord('a'))
# a~z = 97~122

word = input()
arr = [-1] * 26

for i in range(len(word)):
    char = word[i]
    idx = ord(char) - 97
    if arr[idx] == -1:
        arr[idx] = i

print(*arr)