import sys

text = sys.stdin.readline().rstrip()
bomb = sys.stdin.readline().rstrip()
stack = []

for n in text:
    stack.append(n)
    if len(stack) >= len(bomb) and ''.join(stack[-len(bomb):]) == bomb:
        for _ in range(len(bomb)):
            stack.pop()
print(''.join(stack)) if len(stack) > 0 else print("FRULA")