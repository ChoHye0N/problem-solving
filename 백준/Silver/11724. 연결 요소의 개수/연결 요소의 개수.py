import sys

def connected_components(graph):
    def dfs(node):
        visited.add(node)
        for other_node in graph[node]:
            if other_node not in visited:
                dfs(other_node)

    visited = set()
    components_sum = 0

    for node in graph:
        if node not in visited:
            components_sum += 1
            dfs(node)

    return components_sum


n, m = map(int, input().split())
graph = {}

for i in range(1, n+1):
    graph[i] = []

for _ in range(m):
    u, v = map(int, sys.stdin.readline().split())
    if u not in graph[v]:
        graph[v].append(u)
    if v not in graph[u]:
        graph[u].append(v)

print(connected_components(graph))