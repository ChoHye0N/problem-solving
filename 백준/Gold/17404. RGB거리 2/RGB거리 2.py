n = int(input())
li = []
dp = [[0 for _ in range(3)] for _ in range(n)]
ans = float('INF')

for _ in range(n):
    li.append(list(map(int, input().split())))

for case in range(3):
    #첫 번째 인덱스와 마지막 인덱스는 같으면 안됨!
    # R,G,B 고정
    idx = [0, 1, 2]
    x_idx = idx.pop(case)
    dp[0][x_idx] = li[0][x_idx]
    for i in idx:
        dp[0][i] = float('INF')

    for i in range(1, n):
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + li[i][0]
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + li[i][1]
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + li[i][2]

    for i in idx:
        ans = min(ans, dp[n-1][i])

print(ans)