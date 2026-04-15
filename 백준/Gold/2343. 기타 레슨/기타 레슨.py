n, m = map(int, input().split())
a = list(map(int, input().split()))
start, end = max(a), sum(a[m-1:])
ans = 0
while start <= end:
    mid = (start + end)//2
    count = 1
    len = 0

    for i in a:
        if len + i > mid:
            count += 1
            len = i
        else:
            len += i
    if m < count:
        start = mid + 1
    else:
        end = mid - 1
print(start)