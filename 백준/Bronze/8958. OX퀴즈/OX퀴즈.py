n = int(input())
ans = []
for _ in range(n):
    li = input().split('X')
    ans.append(sum(len(x) * (len(x) + 1) // 2 for x in li))

for i in ans:
    print(i)