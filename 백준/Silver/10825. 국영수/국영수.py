from sys import stdin, stdout

n = int(stdin.readline())
li = []

for i in range(n):
    li.append(stdin.readline().split())

li.sort(key=lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))

for i in li:
    stdout.write(f"{i[0]}\n")