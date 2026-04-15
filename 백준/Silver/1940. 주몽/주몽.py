n = int(input())
m = int(input())
li = list(map(int, input().split()))

li = sorted(li)
ans = 0
start, end = 0, len(li)-1

while start < end:
    total = li[start] + li[end]

    if total < m:
        start += 1
    elif total > m:
        end -= 1
    else:
        start += 1
        end -= 1
        ans += 1

print(ans)