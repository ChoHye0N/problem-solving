import itertools

arr = []
carr = []
n, m = map(int, input().split())

for i in range(1, n+1):
    arr.append(i)
for i in list(itertools.permutations(arr, m)):
    carr.append(list((map(str, i))))
for i in carr:
    if sorted(i) == i:
        print(" ".join(i))