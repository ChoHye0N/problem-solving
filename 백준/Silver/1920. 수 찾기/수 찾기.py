def find_num(alen, a1, a2, index):
    start = 0
    end = alen - 1

    while start <= end:
        mid = (start + end) // 2

        if a1[mid] > a2[index]:
            end = mid - 1
        elif a1[mid] < a2[index]:
            start = mid + 1
        else:
            return 1
    return 0

al1 = int(input())
a1 = list(map(int, input().split()))
a1.sort()
al2 = int(input())
a2 = list(map(int, input().split()))
for i in range(al2):
    print(find_num(al1, a1, a2, i))