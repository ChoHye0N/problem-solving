sticks = input()
stack = []
cnt = 0

for i in range(len(sticks)):
    if sticks[i] == '(':
        stack.append(sticks[i])
    else:
        if sticks[i-1] == '(':
            stack.pop()
            cnt += len(stack)
        else:
            stack.pop()
            cnt += 1

print(cnt)