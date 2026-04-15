import sys
input = sys.stdin.readline

n = int(input())
li = []
for i in range(n):
    info = input().split()
    li.append([str(i), info[0], info[1]])

li = sorted(li, key=lambda x: (int(x[1]), int(x[0])))

for i in li:
    sys.stdout.write(i[1] +" " + i[2] + "\n")