import sys

n, c = map(int, sys.stdin.readline().split())
x = sorted([int(sys.stdin.readline()) for _ in range(n)])

start, end = 1, x[-1] - x[0]
maxLen = 0

while start <= end:
    count, prePos = 1, x[0]
    mid = (start + end) // 2

    for i in range(1, n):
        if x[i] - prePos >= mid:
            count += 1
            prePos = x[i]

    if count >= c:
        maxLen = mid
        start = mid + 1
    else:
        end = mid - 1

print(maxLen)