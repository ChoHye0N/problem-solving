from sys import stdin
input = stdin.readline

n = int(input())
position_arr = []

for i in range(n):
    x, y = map(int, input().split())
    position_arr.append((x, y))

ans = 0

for i in range(n):
    x1, y1 = position_arr[i]
    x2, y2 = position_arr[(i + 1) % n]
    ans += 0.5 * (x1 * y2 - x2 * y1)

print(round(abs(ans), 1))