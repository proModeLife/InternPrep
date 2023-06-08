// https://leetcode.com/problems/next-greater-element-i

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1Idx= {n : i for i,n in enumerate(nums1)}
        res = [-1]*len(nums1)
        stack=[]
        for i in range(len(nums2)):
            while stack and nums2[i]>stack[-1]:
                res[nums1Idx[stack[-1]]]=nums2[i]
                stack.pop()
            if nums2[i] in nums1Idx:
                stack.append(nums2[i])
        return res
            
