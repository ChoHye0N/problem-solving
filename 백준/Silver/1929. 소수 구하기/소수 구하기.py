def eratos(M, N):
    arr = [True]*(N+1)
    arr[0] = arr[1] = False
    for i in range(2, int(N**0.5)+1):
        if arr[i]:
            for j in range(i+i, N+1, i):
                arr[j] = False
    for i in range(M, N+1):
        if arr[i]:
            print(i)
m, n = input().split()
eratos(int(m), int(n))