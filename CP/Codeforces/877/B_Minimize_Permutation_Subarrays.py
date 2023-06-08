def permute_the_array(arr, n):
    index_arr = [0] * n

    # Store the indices of the elements present in arr.
    for i in range(n):
        index_arr[arr[i] - 1] = i

    mini = n
    maxi = 0
    count = 0

    # Store the maximum and minimum index of the
    # elements from 1 to i.
    for i in range(n):
        # Update maxi and mini, to store minimum and maximum
        # index for permutation of elements from 1 to i+1
        mini = min(mini, index_arr[i])
        maxi = max(maxi, index_arr[i])

        # If difference between maxi and mini is equal to i
        if (maxi - mini == i):
            # Increase count
            count += 1

    # Return final count
    return count
      

T = int(input())
for _ in range(T):
   n = int(input())
   p = list(map(int, input().split()))
   ans=permute_the_array(p.copy(),n)
   ai,aj=1,1
   for i in range(n):
       for j in range(i,n):
           p[i],p[j]=p[j],p[i]
           val=permute_the_array(p.copy(),n)
           p[i],p[j]=p[j],p[i]
           if val<ans:
               ai,aj=i+1,j+1
               ans=val
   print(ai,aj)

