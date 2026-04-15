import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))
prefix_sum = [0]

for i in range(n):
    prefix_sum.append(prefix_sum[i] + arr[i])

for _ in range(m):
    n1, n2 = map(int, input().split())
    sys.stdout.write(str(prefix_sum[n2] - prefix_sum[n1-1])+"\n")