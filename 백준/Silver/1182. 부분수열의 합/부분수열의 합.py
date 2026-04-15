import itertools

def combinations_sum(n, s, arr):
    cnt = 0
    for i in range(1, n+1):
        comb_list = list(itertools.combinations(arr, i))
        for j in range(len(comb_list)):
            if sum(comb_list[j]) == s:
                cnt += 1
    return cnt

n, s = map(int, input().split())
arr = list(map(int, input().split()))
print(combinations_sum(n, s, arr))