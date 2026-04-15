import sys
input = sys.stdin.readline

while True:
    arr = list(map(int, input().split()))
    arr = sorted(arr)
    if arr == [0, 0, 0]:
        break
    print("right") if arr[0]**2+arr[1]**2 == arr[2]**2 \
        else print("wrong")