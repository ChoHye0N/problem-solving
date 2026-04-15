def fibonacci_count(n):
    if n == 0:
        return [1, 0]

    dp = [0]*(n+1)
    dp[1] = 1

    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]

    return dp[n-1:n+1]

t = int(input())

for i in range(t):
    n = int(input())
    count = fibonacci_count(n)
    print(count[0], count[1])