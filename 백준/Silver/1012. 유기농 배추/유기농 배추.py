import sys

def find_cabbage_areas(field, visited, x, y):
    stack = [(x, y)]
    visited[x][y] = True

    while stack:
        cx, cy = stack.pop()

        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]

        for i in range(4):
            nx, ny = cx + dx[i], cy + dy[i]
            if 0 <= nx < m and 0 <= ny < n and field[nx][ny] == 1 and not visited[nx][ny]:
                stack.append((nx, ny))
                visited[nx][ny] = True

t = int(input())
count = 0

while count < t:
    m, n, k = map(int, input().split())
    field = [[0] * n for _ in range(m)]
    visited = [[False] * n for _ in range(m)]
    ans = 0

    for _ in range(k):
        x, y = map(int, sys.stdin.readline().split())
        field[x][y] = 1

    for i in range(m):
        for j in range(n):
            if field[i][j] == 1 and not visited[i][j]:
                find_cabbage_areas(field, visited, i, j)
                ans += 1

    print(ans)
    count += 1
