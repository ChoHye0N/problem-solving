def printer(priorities, location):
    printCount = 0

    while priorities:
        temp = priorities.pop(0)
        if not priorities or temp >= max(priorities):
            printCount += 1
            if location == 0:
                return printCount
        else:
            priorities.append(temp)

        location = (location - 1) % len(priorities)

answer = []
maxCount = int(input())
for i in range(maxCount):
    noneNum, location = input().split(" ")
    priorities = list(input().split())
    answer.append(str(printer(priorities, int(location))))
print("\n".join(answer))