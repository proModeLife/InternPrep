def get_sum(l,k):
    if l<k:
        return 0
    else:
        curr=0
        for i in range(k,l+1):
            curr+=l-i+1
        return curr
         

def count_vacation_dates(n, k, q, a):
    ans = 0
    i, j = 0, 0
    while j < n:
        if a[j] > q:
            ans += get_sum(j-i, k)
            while j < n and a[j] > q:
                j += 1
            i = j
        else:
            j += 1
    ans += get_sum(j-i, k)

    return ans

t = int(input())

for _ in range(t):
    n, k, q = map(int, input().split())
    a = list(map(int, input().split()))
    print(count_vacation_dates(n, k, q, a))