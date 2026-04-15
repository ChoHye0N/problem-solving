k, n = map(int, input().split())
li = []

for _ in range(k):
    li.append(int(input()))

ans = 0
start = 1
end = max(li)

while start <= end:
    mid = (start+end)//2
    line_count = 0
    for i in li:
        line_count += i//mid
    if line_count >= n:
        ans = mid
        start = mid+1
    else:
        end = mid-1
print(ans)