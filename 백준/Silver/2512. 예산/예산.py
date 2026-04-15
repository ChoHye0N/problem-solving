n = int(input())
a = list(map(int, input().split()))
m = int(input())
start, end = 0, max(a)
ans = 0
while start <= end:
    mid = (start + end)//2
    budget = 0
    for i in a:
        budget += min(i, mid)
    if m >= budget:
        ans = mid
        start = mid + 1
    else:
        end = mid - 1
print(ans)