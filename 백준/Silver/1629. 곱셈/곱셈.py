from sys import stdout

a, b, c = map(int, input().split())
stdout.write(str(pow(a, b, c)))