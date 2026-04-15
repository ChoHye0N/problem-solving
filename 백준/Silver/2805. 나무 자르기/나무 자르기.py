n, m = map(int, input().split())
a = list(map(int, input().split()))
start, end = 0, max(a)
ans = 0
while start <= end:
    mid = (start + end)//2
    total = 0
    for i in a:
        if i > mid:
            total += i - mid
    if total >= m:
        ans = mid
        start = mid + 1
    else:
        end = mid - 1
print(ans)