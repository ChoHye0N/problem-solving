import math as m

n = int(input())

a = []

for _ in range(n):

    x1, y1, r1, x2, y2, r2 = map(int, input().split())

    d = m.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

    

    if d == 0 and r1 == r2:

        a.append(-1)

    elif d == r1 + r2 or d == abs(r1 - r2):

        a.append(1)

    elif d < r1 + r2 and d > abs(r1 - r2):

        a.append(2)

    else:

        a.append(0)

for i in range(n):

    print(a[i])

