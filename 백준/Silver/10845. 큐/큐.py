import sys

n = int(input())
queue = []

for _ in range(n):
    line = sys.stdin.readline().rstrip().split(" ")
    if line[0] == "push":
        queue.append(line[1])
        continue

    elif line[0] == "pop":
        if queue:
            print(queue.pop(0))
        else:
            print(-1)
        continue

    elif line[0] == "size":
        print(len(queue))
        continue

    elif line[0] == "empty":
        if queue:
            print(0)
        else:
            print(1)
        continue

    elif line[0] == "front":
        if queue:
            print(queue[0])
        else:
            print(-1)
        continue

    elif line[0] == "back":
        if queue:
            print(queue[-1])
        else:
            print(-1)