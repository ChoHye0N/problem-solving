import sys
input = sys.stdin.readline

n = int(input())
li = list(map(int, input().split()))
max_li = max(li)
score = [0] * n
check = [0] * (max_li + 1)

for i in range(n):
    check[li[i]] = i+1

for i in range(n):
    for j in range(li[i]*2, max_li+1, li[i]):
        if not check[j] == 0:
            score[i] += 1
            score[check[j]-1] -= 1

for i in range(n):
    sys.stdout.write(str(score[i]) + " ")