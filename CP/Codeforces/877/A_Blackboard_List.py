from itertools import combinations

def find_initial_number(n, a):
    possible_initial_numbers = set()
    canTry=[True]*n
    for i in range(n):
        if canTry[i]:
         dp=[False]*n
         dp[i]=True
         canTry[i]=False
         for j in range
            

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    initial_number = find_initial_number(n, a)
    if initial_number is not None:
        print(initial_number)
    else:
        print("No possible initial number")