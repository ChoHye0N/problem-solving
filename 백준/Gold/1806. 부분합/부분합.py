from sys import stdin
def two_pointer(nums, sum, li):
    min_list_len = nums+1
    start = 0
    end = 0
    part_sum = 0

    while end<=nums:
        if part_sum>=sum:
            min_list_len = min(min_list_len, end - start)
            part_sum -= li[start]
            start += 1
        elif part_sum<sum:
            if end == nums:
                break
            part_sum += li[end]
            end += 1
    if min_list_len == nums+1:
        return 0
    else:
        return min_list_len

n, s = map(int, input().split())
li = list(map(int, stdin.readline().split()))
print(two_pointer(n, s, li))