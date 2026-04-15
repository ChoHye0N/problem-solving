n = int(input())
li = sorted(list(map(int, input().split())))

prefix_sum = [0]

for i in range(n):
    prefix_sum.append(prefix_sum[i] + li[i])
    
print(sum(prefix_sum))