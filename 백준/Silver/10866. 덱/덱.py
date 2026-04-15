import sys

n = int(input())
deque = []

for _ in range(n):
    line = sys.stdin.readline().rstrip().split(" ")
    if line[0] == "push_front":
        deque.insert(0, line[1])
        continue

    elif line[0] == "push_back":
        deque.append(line[-1])
        continue

    elif line[0] == "pop_front":
        if deque:
            print(deque.pop(0))
        else:
            print(-1)
        continue

    elif line[0] == "pop_back":
        if deque:
            print(deque.pop(-1))
        else:
            print(-1)
        continue

    elif line[0] == "size":
        print(len(deque))
        continue

    elif line[0] == "empty":
        if deque:
            print(0)
        else:
            print(1)
        continue

    elif line[0] == "front":
        if deque:
            print(deque[0])
        else:
            print(-1)
        continue

    elif line[0] == "back":
        if deque:
            print(deque[-1])
        else:
            print(-1)