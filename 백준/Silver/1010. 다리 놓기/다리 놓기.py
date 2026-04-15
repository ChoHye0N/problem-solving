def combinations(n, r):
    c = 1
    for i in range(r):
        c *= n - i
        c //= i + 1
    return c
ans = []
for i in range(int(input())):
    a, b = map(int, input().split())
    if a <= b // 2:
        ans.append(combinations(b, a))
    else:
        ans.append(combinations(b, b - a))
for i in ans:
    print(i)