n = int(input())
matrix_list = []


for i in range(n):
    if i == 0:
        matrix_list.extend(list(map(int, input().split())))
    else:
        matrix_list.append(list(map(int, input().split()))[1])

# init dp
dp = [[0 for _ in range(n)] for _ in range(n)]

# DP processing
for L in range(1, n):
    for i in range( n-L):
        j = i + L
        dp[i][j] = 2**31
        for k in range(i, j):
            temp = dp[i][k] + dp[k+1][j] + matrix_list[i-1]*matrix_list[k]*matrix_list[j]
            if temp < dp[i][j]:
                dp[i][j] = temp

print(dp[0][n-1])