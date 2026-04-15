import sys
input = sys.stdin.readline

def solution(arr, n):
    ans = []
    min_n = float('INF')

    for mid in range(n - 2):
        start, end = mid + 1, n - 1

        while start < end:
            total = li[start] + li[end] + li[mid]
            abs_total = abs(total)

            if abs_total < min_n:
                min_n = abs_total
                ans = [li[start], li[mid], li[end]]

            if total < 0:
                start += 1
            elif total > 0:
                end -= 1
            else:
                break
    return sorted(ans)

#시간초과 문제 해결을 위한 main 함수 이용
if __name__ == '__main__':
    n = int(input())
    li = sorted(list(map(int, input().split())))

    print(*solution(li, n))