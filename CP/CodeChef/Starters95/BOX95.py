for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    x = max(a)
    mxbit = 60
    while x & (1<<mxbit) == 0: mxbit -= 1
    
    ct = 0
    for i in range(n):
        ct += a[i] >> mxbit
    print((ct + 1)//2)