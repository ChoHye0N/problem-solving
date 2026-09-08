import sys
input = sys.stdin.readline

s = input().strip()
n = len(s)

is_pal = [[False] * n for _ in range(n)]

for i in range(n):
    is_pal[i][i] = True

for i in range(n - 1):
    if s[i] == s[i + 1]:
        is_pal[i][i + 1] = True

for length in range(3, n + 1):
    for i in range(n - length + 1):
        j = i + length - 1
        if s[i] == s[j] and is_pal[i + 1][j - 1]:
            is_pal[i][j] = True

dp = [0] * (n + 1)
for i in range(1, n + 1):
    dp[i] = i
    for j in range(i):
        if is_pal[j][i - 1]:
            dp[i] = min(dp[i], dp[j] + 1)

print(dp[n])
