vps = []
for i in range(int(input())):
    stack = []
    vps_in = input()
    if vps_in[0] == ')':
        vps.append("NO")
        continue
    for j in vps_in:
        stack.append(j)
        if len(stack) > 1 and stack[-1] == ')' and stack[-2] == '(':
            stack.pop()
            stack.pop()
    vps.append("YES" if not stack else "NO")

for i in vps:
    print(i)