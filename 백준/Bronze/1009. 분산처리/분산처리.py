t = int(input())
ans = []
for i in range(t):
    a, b = map(int, input().split())
    temp = a
    li = [a%10]
    for j in range(10):
        temp = (temp*a)%10
        if temp == 0:
            li[0] = 10
            break
        if li[0] == temp:
            break
        li.append(temp)
    ans.append(li[b%len(li)-1])
for i in ans:
    print(i)