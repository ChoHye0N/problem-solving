n = int(input())
dp = [0]+[1]*9
for i in range(2, n+1):
    nextDp = [0]*10
    for j in range(10):
        if j == 0:
            nextDp[j] = dp[j+1]
        elif j == 9:
            nextDp[j] = dp[j-1]
        else:
            nextDp[j] = dp[j-1] + dp[j+1]
    dp = nextDp
print(sum(dp)%1000000000)