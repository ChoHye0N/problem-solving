n = int(input())
a = list(map(int, input().split()))

min = float('inf')
ans = None
start, end = 0, n - 1

while start < end and end >= 0:
    total = a[start] + a[end]
    absSum = abs(total)

    if absSum < min:
        min = absSum
        ans = [a[start], a[end]]

    if total < 0:
        start += 1
    elif total > 0:
        end -= 1
    else:
        break

print(ans[0], ans[1])