def is_hansu(n):
    s = str(n)
    if len(s) == 1:
        return True
    for i in range(2, len(s)):
        if int(s[1]) - int(s[0]) != int(s[i]) - int(s[i-1]):
            return False
    return True

count = 0
for i in range(1, int(input())+1):
    if is_hansu(i):
        count += 1
print(count)