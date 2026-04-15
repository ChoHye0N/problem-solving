import sys

n = int(input())
stack = []

for _ in range(n):
    line = sys.stdin.readline().rstrip().split(" ")
    if line[0] == "push":
        stack.append(line[1])
        continue
        
    elif line[0] == "pop":
        if stack:
            print(stack.pop())
        else:
            print(-1)
        continue
        
    elif line[0] == "size":
        print(len(stack))
        continue
        
    elif line[0] == "empty":
        if stack:
            print(0)
        else:
            print(1)
        continue
        
    elif line[0] == "top":
        if stack:
            print(stack[-1])
        else:
            print(-1)