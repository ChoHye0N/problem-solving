import sys

input = sys.stdin.readline

while True:
    line = input()
    if line == "":
        break

    arr = list(map(int, line.strip().split()))
    result = []

    for i in range(len(arr)):
        left = arr[i - 1] if i - 1 >= 0 else 1
        mid = arr[i]
        right = arr[i + 1] if i + 1 < len(arr) else 1

        result.append(left * mid * right)

    print(' '.join(map(str, result)))