max_num_arr = []

for i in range(9):
    max_num_arr.append(int(input()))

max_num = max(max_num_arr)
max_index = max_num_arr.index(max_num)
print(max_num)
print(max_index + 1)