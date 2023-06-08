t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    ans = ""
    queue = []
    i = 0
    while i < len(s):
        if not queue:
            queue.append(s[i])
            i += 1
        else:
            if s[i] == queue[0]:
                queue = []
                ans += s[i]
                i += 1
            else:
                queue.append(s[i])
                i += 1
    print(ans)