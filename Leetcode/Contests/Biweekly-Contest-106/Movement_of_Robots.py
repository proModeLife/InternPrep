class Solution:
    def sumDistance(self, nums: List[int], s: str, d: int) -> int:
        for i in range(len(nums)):
            nums[i]+= ((-1)**(int(s[i]=='L')))*d
        nums.sort()
        pre=[0]*(len(nums)+1)
        pre[0]=nums[0]
        ans=0
        for i in range(1,len(nums)):
            pre[i]=pre[i-1]+nums[i]
            ans+=i*nums[i]-pre[i-1]
            ans%=int(1e9+7)
        return ans