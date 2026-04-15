import sys

while True:
    text = sys.stdin.readline().rstrip()

    if text[0] == '.':
        break

    text = text.replace(' ', '')
    bracket_check = ['(', ')', '[', ']']
    brackets = list(filter(lambda x: x in bracket_check, text))
    stack = []

    for n in brackets:
        stack.append(n)
        if len(stack) > 1:
            if stack[-1] == ')' and stack[-2] == '(':
                stack.pop()
                stack.pop()
            elif stack[-1] == ']' and stack[-2] == '[':
                stack.pop()
                stack.pop()

    if len(stack) == 0:
        print("yes")
    else:
        print("no")