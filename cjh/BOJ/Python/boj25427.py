import sys

n = int(sys.stdin.readline().strip())
s = sys.stdin.readline().strip()

cnt_d = 0
cnt_k = 0
cnt_s = 0
cnt_h = 0

for l in s:
    if l == "D":
        cnt_d += 1
    elif l == "K":
        cnt_k += cnt_d
    elif l == "S":
        cnt_s += cnt_k
    elif l == "H":
        cnt_h += cnt_s
print(cnt_h)