import sys

n, m = map(int, input().split())
listen_look = set()
ans = []

for i in range(n):
    name = sys.stdin.readline().strip()
    listen_look.add(name)

for i in range(m):
    name = sys.stdin.readline().strip()
    if name in listen_look:
        ans.append(name)

ans.sort()
print(len(ans))
for i in ans:
    sys.stdout.write(i+"\n")