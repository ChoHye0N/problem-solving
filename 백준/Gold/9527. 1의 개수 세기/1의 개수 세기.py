def count_ones(num):
    total = 0
    k = num

    while k > 0:
        n = k.bit_length()-1
        total += int(2**(n-1)*n) + k-((2**n)-1)
        k -= 2**n

    return total


a, b = map(int, input().split())
print(count_ones(b) - count_ones(a-1))