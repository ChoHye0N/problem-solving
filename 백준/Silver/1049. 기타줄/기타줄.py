import sys
input = sys.stdin.readline

n, m = map(int, input().split())
min_package, min_each = 1001, 1001

for i in range(m):
    package_price, each_price = map(int, input().split())
    min_package = min(min_package, package_price)
    min_each = min(min_each, each_price)

# 패키지로만 구매하는 비용
package_cost = min_package * n

# 개별로만 구매하는 비용
each_cost = min_each * n

# 혼합으로 구매하는 비용
mixed_cost = (n // 6) * min_package + (n % 6) * min_each
mixed_cost = min(mixed_cost, min_package * (n // 6 + 1))

total_cost = min(package_cost, each_cost, mixed_cost)
print(total_cost)