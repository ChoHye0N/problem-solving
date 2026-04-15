def Seven_Dwarfs(height):
    for i in range(9):
        for j in range(i+1, 9):
            temp = list(height[:])
            temp.pop(i)
            temp.pop(j-1)
            if sum(temp) == 100:
                temp.sort()
                return temp

height = []
for i in range(9):
    height.append(int(input()))
for i in Seven_Dwarfs(height):
    print(f"{i}")