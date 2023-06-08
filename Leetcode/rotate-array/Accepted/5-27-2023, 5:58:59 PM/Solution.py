// https://leetcode.com/problems/rotate-array

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k%=len(nums)
        if k==0:
            return
        visited= [False]*len(nums)
        for i in range(len(nums)-k):
            carry = nums[i]
            while not visited[i]:
                visited[i]=True
                tmp = nums[(i+k)%len(nums)]
                nums[(i+k)%len(nums)]=carry
                carry=tmp
                i=(i+k)%len(nums)
                
