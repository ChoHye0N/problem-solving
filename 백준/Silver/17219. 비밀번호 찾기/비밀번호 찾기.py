from sys import stdin, stdout
input = stdin.readline

n, m = map(int, input().split())
dic = {}

for _ in range(n):
    arr = input().split()
    dic[arr[0]] = arr[1]

for _ in range(n, n+m):
    find_password = dic.get(input().rstrip())
    if find_password:
        stdout.write(find_password+"\n")