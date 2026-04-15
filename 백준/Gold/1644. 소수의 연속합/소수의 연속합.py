def prime(num):
    is_prime = [True]*(num+1)
    is_prime[0] = is_prime[1] = False
    prime_arr = []

    for i in range(2, int(num ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i*2, num+1, i):
                    is_prime[j] = False
    for i in range(num+1):
        if is_prime[i]:
            prime_arr.append(i)
    return prime_arr

n = int(input())
prime_arr = prime(n)
start, end, count = 0, 0, 0

while end <= len(prime_arr):
    total = sum(prime_arr[start:end+1])
    if total < n:
        end += 1
    elif total > n:
        start += 1
    else:
        start += 1
        count += 1

print(count)