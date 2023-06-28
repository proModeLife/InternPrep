class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        res= [False]*len(nums)
        for i in nums:
            res[i-1]=True
        ans= []
        for i in range(len(res)):
            if res[i]==False:
                ans+=[i+1]
        return ans
