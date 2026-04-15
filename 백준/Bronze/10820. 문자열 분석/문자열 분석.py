while True:
    try:
        answer = [0,0,0,0]
        temp = input()
        for i in temp:
            if (ord(i)>96) and (ord(i)<123):
                answer[0] += 1
            elif (ord(i)>64) and (ord(i)<91):
                answer[1] += 1
            elif (ord(i) > 47) and (ord(i) < 58):
                answer[2] += 1
            elif ord(i) == 32:
                answer[3] += 1
        for i in range(len(answer)):
            print(answer[i], end=' ')
    except:
        break