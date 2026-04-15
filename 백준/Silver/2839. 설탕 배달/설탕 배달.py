def minimum_suger_bags(n):
    max_suger_bags = n//5

    for i in range(max_suger_bags, -1, -1):
        remaining_weight = n - (i*5)

        if remaining_weight % 3 == 0:
            return i + (remaining_weight//3)

    return -1


n = int(input())
print(minimum_suger_bags(n))