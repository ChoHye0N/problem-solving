import sys

#스택을 이용한 사이클 개수 확인
def connected_components(graph):
    visited = set()
    components_sum = 0

    for start_node in graph:
        if start_node not in visited:
            components_sum += 1
            stack = [start_node]

            while stack:
                node = stack.pop()
                visited.add(node)

                for neighbor in graph[node]:
                    if neighbor not in visited:
                        stack.append(neighbor)

    return components_sum

n, m = map(int, input().split())
graph = {}

# 노드 초기화
for i in range(n * m):
    graph[i] = []

for row in range(n):
    row_arr = list(sys.stdin.readline().rstrip())

    for col in range(m):
        u, v = row * m + col, 0

        if row_arr[col] == 'U' and row > 0:
            v = u - m
        elif row_arr[col] == 'D' and row < n - 1:
            v = u + m
        elif row_arr[col] == 'L' and col > 0:
            v = u - 1
        elif row_arr[col] == 'R' and col < m - 1:
            v = u + 1

        # 간선 연결 확인
        if v != 0 and v not in graph[u]:
            graph[u].append(v)
        if u not in graph[v]:
            graph[v].append(u)

print(connected_components(graph))
