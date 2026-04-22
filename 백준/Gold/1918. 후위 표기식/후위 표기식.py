precedence = {'(': 0, '+': 1, '-': 1, '*': 2, '/': 2}
stack = []
answer = []

for i in list(input()):
    if i.isalpha():
        answer.append(i)
    elif i == '(':
        stack.append(i)
    elif i == ')':
        while stack and stack[-1] != '(':
            answer.append(stack.pop())
        stack.pop()
    else:
        while stack and precedence[stack[-1]] >= precedence[i]:
            answer.append(stack.pop())
        stack.append(i)

while stack:
    answer.append(stack.pop())

print(''.join(answer))