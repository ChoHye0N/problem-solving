from sys import stdin
input = stdin.readline

stack = []
k = int(input())

for i in range(k):
    num = int(input())

    if num:
        stack.append(num)
    else:
        stack.pop()

print(sum(stack))