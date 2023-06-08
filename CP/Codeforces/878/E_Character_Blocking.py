# function to check if two strings are equal ignoring blocked characters
def are_strings_equal(s1, s2, blocked):
    for i in range(len(s1)):
        if i+1 not in blocked and s1[i] != s2[i]:
            return False
    return True

# main function to process each test case
def process_testcase():
    # read input
    s1 = input().strip()
    s2 = input().strip()
    t, q = map(int, input().split())

    # initialize set of blocked characters
    blocked = set()

    # process each query
    for i in range(q):
        query = input().split()
        if query[0] == "1":
            p = int(query[1])
            blocked.add(p)
        elif query[0] == "2":
            p1 = int(query[2])
            p2 = int(query[4])
            if p1 not in blocked and p2 not in blocked:
                s1 = s1[:p1-1] + s2[p2-1] + s1[p1:p2-1] + s1[p2:]
                s2 = s2[:p2-1] + s1[p1-1] + s2[p2:p1-1] + s2[p1:]
        else: # query[0] == "3"
            if are_strings_equal(s1, s2, blocked):
                print("YES")
            else:
                print("NO")

# read number of test cases
t = int(input())

# process each test case
for i in range(t):
    process_testcase()