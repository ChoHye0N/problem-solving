n = int(input())
ans = []
for _ in range(n):
    num = ""
    word = input()
    for i in word:
        if i.isdigit():
            num += i
        else:
            num += " "
    for i in list(filter(lambda x: not x == '', num.split(" "))):
        ans.append(int(i))
for i in sorted(ans):
    print(i)