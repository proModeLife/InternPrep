// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        arr=nums.copy()
        ans=1
        i,j=0,0
        while j<len(nums):
            if nums[i]==nums[j]:
                ans=max(ans,j-i+1)
                j+=1
            else:
                if k<0 or (k==0 and nums[i]!=nums[j]):
                    k+=arr[i]-nums[i]
                    i+=1
                else:
                    for t in range(i,j):
                        val = min(k,nums[j]-nums[t])
                        k-=val
                        nums[t]+=val
                        if val==0:
                            break
        return ans
            