import heapq

def find_max_waiting_time(n, a):
    while len(a) < 3:
        a.append(0)
    a.sort()
    carvers = [(a[0], 0), (a[1], 1), (a[2], 2)]
    max_waiting_time = 0
    for i in range(3, n):
        closest_carver = min(carvers, key=lambda x: abs(x[0] - a[i]))
        waiting_time = abs(closest_carver[0] - a[i])
        max_waiting_time = max(max_waiting_time, waiting_time)
        carvers[closest_carver[1]] = (a[i], closest_carver[1])

    return max_waiting_time

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    print(find_max_waiting_time(n, a))