import sys
input = sys.stdin.readline

def max_mode(mode):
    if len(mode) > 1:
        if mode[-1][1] == mode[-2][1]:
            return mode[-2][0]
        else:
            return mode[-1][0]
    else:
        return mode[-1][0]

n = int(input())
li = []
mode = {}

for i in range(n):
    num = int(input())
    if not num in mode:
        mode[num] = 1
    else:
        mode[num] += 1
    li.append(num)

sort_li = sorted(li)
mode = sorted(mode.items(), key=lambda x: (x[1], -x[0]))

print(round(sum(sort_li)/n))
print(sort_li[n//2])
print(max_mode(mode))
print(sort_li[-1] - sort_li[0])