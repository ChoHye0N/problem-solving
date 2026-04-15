import sys
input = sys.stdin.readline

def stack_check(arr, stack):
    ans = []
    idx = 1
    count = 0

    while count < len(arr):
        if stack[-1] == arr[count]:
            stack.pop()
            ans.append("-")
            count += 1
        elif stack[-1] < arr[count]:
            ans.append("+")
            stack.append(idx)
            idx += 1
        else:
            return 0

    return ans

n = int(input())
arr = []
stack = [0]

for _ in range(n):
    arr.append(int(input()))

solution = stack_check(arr, stack)

if solution == 0:
    print("NO")
else:
    for i in solution:
        print(i)