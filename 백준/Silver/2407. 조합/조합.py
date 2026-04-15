def combinations(n, r):
    c = 1
    for i in range(r):
        c *= n - i
        c //= i + 1
    return c

a, b = map(int, input().split())
if a <= b // 2:
    ans = combinations(a, b)
else:
    ans = combinations(a, a - b)
print(ans)