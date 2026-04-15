cnt=0
car_in = {}
car_out = []
car_num = int(input())
for i in range(car_num):
    car_in[input()] = i
for i in range(car_num):
    car_out.append(input())
for i in range(car_num-1):
    for j in range(i + 1, car_num):
        if car_in[car_out[i]] > car_in[car_out[j]]:
            cnt+=1
            break
print(cnt)