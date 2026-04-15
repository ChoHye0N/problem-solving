import heapq
import sys

n = int(input())
heap = []

for i in range(n):
    num = int(sys.stdin.readline())
    if num:
        heapq.heappush(heap, num)
    else:
        if not heap:
            sys.stdout.write("0\n")
        else:
            sys.stdout.write(str(heapq.heappop(heap))+"\n")