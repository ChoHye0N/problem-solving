import sys
from collections import deque
input = sys.stdin.readline


def min_topology_sort(n, k, build_cost, graph, edges, target):
    dp = [0] * (n + 1)

    adj_list = [[] for _ in range(n + 1)]

    for u, v in edges:
        adj_list[u].append(v)

    queue = deque()

    for node, degree in graph:
        if degree == 0:
            queue.append(node)
            dp[node] = build_cost[node - 1]

    # 위상 정렬 수행
    while queue:
        current = queue.popleft()
        for neighbor in adj_list[current]:
            graph[neighbor - 1][1] -= 1
            dp[neighbor] = max(dp[neighbor], dp[current] + build_cost[neighbor - 1])
            if graph[neighbor - 1][1] == 0:
                queue.append(neighbor)

    return dp[target]


t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    build_cost = list(map(int, input().split()))
    graph = [[i + 1, 0] for i in range(n)]

    # 간선 정보 저장
    edges = []
    
    for _ in range(k):
        u, v = map(int, input().split())
        edges.append((u, v))
        graph[v - 1][1] += 1

    target = int(input())

    print(min_topology_sort(n, k, build_cost, graph, edges, target))
