from sys import stdin, stdout

n, m = map(int, input().split())
li = []
words = {}
for i in range(n):
    w = stdin.readline().rstrip()
    if len(w) >= m:
        if w in words:
            words[w] += 1
        else:
            words[w] = 0
li = sorted(words.items(), key=lambda x: (-x[1], -len(x[0]), x[0]))

for i in li:
    stdout.write(f"{i[0]}\n")