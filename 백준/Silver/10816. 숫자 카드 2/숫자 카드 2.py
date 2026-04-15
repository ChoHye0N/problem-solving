import sys
input = sys.stdin.readline

ans = []
n = int(input())
card_list = {}

li_1 = list(map(int, input().split()))
for card in li_1:
    if not card_list.get(card):
        card_list[card] = 1
    else:
        card_list[card] += 1

m = int(input())
li_2 = list(map(int, input().split()))
for card in li_2:
    if not card_list.get(card):
        ans.append(0)
    else:
        ans.append(card_list[card])

print(*ans)