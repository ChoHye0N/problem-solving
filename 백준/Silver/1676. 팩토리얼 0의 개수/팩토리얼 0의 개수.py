num = int(input())
count = 0
while num >= 5:
    count, num = count + num // 5, num // 5
print(count)