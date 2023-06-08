def count_ways(n, k):
    if n >= (1 << k) - 1:
        return 1 << k
    else:
        count = 0
        while n > 0 and k >= 0:
            if (1 << k) & n:
                n -= 1 << k
                count += 1 << k
            k -= 1
        return count + 1
t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    print(count_ways(n, k))