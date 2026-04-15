import itertools
arr = []
n = int(input())
for i in range(n):
    arr.append(i+1)
for i in list(itertools.permutations(arr, n)):
     print(" ".join(map(str, i)))