import sys
input = sys.stdin.readline

def min_apps_cost(apps_count, max_memory, memory, cost):
    total_cost = sum(cost)

    # DP 생성
    dp = [[0] * (total_cost+1) for _ in range(apps_count+1)]

    for i in range(1, apps_count+1):
        for j in range(total_cost+1):
            if cost[i-1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i-1]]+memory[i-1])

    # 최소 비용을 찾아서 반환
    for count in range(total_cost+1):
        if dp[apps_count][count] >= max_memory:
            return count

n, m = map(int, input().split())
memory = list(map(int, input().split()))
cost = list(map(int, input().split()))

print(min_apps_cost(n, m, memory, cost))
