x, y = map(int, input().split())
z = int(y*100/x)
ans = 0

start, end = 0, 1000000001
while start < end:
    mid = (start + end) // 2
    current_z = int(((y + mid)* 100 / (x + mid)))

    if current_z > z:
        end = mid
    else:
        start = mid + 1
    ans = start

if ans >= 1000000001:
    print(-1)
else:
    print(ans)