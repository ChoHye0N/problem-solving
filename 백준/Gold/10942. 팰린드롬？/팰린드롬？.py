import sys
input = sys.stdin.readline

n = int(input())
li = list(input().split())
m = int(input())

dp = [[0] * n for _ in range(n)]

for i in range(n):
    dp[i][i] = 1

for i in range(n - 1, -1, -1):
    for j in range(i + 1, n):
        if li[i] == li[j] and (j - i == 1 or dp[i + 1][j - 1] == 1):
            dp[i][j] = 1

for _ in range(m):
    left, right = map(int, input().split())
    left -= 1
    right -= 1

    if dp[left][right]:
        print(1)
    else:
        print(0)