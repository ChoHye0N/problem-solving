import sys

input = sys.stdin.readline

N, L = map(int, input().split())
total_panel_count = 0
current_position = 0
hole_position_list = []

for _ in range(N):
    start, end = map(int, input().split())
    hole_position_list.append((start, end))

hole_position_list = sorted(hole_position_list, key=lambda x: x[0])

for start, end in hole_position_list:
    if end <= current_position:
        continue

    # 시작 위치가 현재 위치보다 앞에 있으면 시작 위치로 조정
    if start > current_position:
        current_position = start

    panel_count = (end - current_position + L - 1) // L
    total_panel_count += panel_count

    current_position += panel_count * L

print(total_panel_count)
