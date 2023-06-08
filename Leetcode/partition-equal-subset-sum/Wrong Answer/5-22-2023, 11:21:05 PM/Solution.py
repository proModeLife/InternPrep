// https://leetcode.com/problems/partition-equal-subset-sum

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        target=sum(nums)
        if target%2==1:
            return False
        else:
            target/=2
        dp=set()
        dp.add(0)
        nums.sort()
        l,r=0,len(nums)-1
        while l<r:
            lDP=set()
            for t in dp:
                if t+nums[r]==target:
                    return True
                lDP.add(t+nums[r])
                lDP.add(t)
            dp=set()
            for t in lDP:
                if t+nums[l]==target:
                    return True
                dp.add(t+nums[l])
                dp.add(t)
        if l==r:
            for t in dp:
                if t+nums[r]==target:
                    return True
        return False

            