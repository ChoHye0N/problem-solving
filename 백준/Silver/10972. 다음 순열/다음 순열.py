def next_permutation(a, n):
    i = n - 2
    while i >= 0 and a[i] >= a[i + 1]:
        i -= 1
    if i < 0:
        return False
    j = n - 1
    while j > i and a[i] >= a[j]:
        j -= 1
    a[i], a[j] = a[j], a[i]
    a[i + 1:] = reversed(a[i + 1:])
    return True

n = int(input())
a = list(map(int, input().split()))
if next_permutation(a, n):
    print(*a)
else:
    print(-1)