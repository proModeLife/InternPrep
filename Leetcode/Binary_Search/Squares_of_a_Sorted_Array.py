class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        if not nums:
            return None
        i = 0
        while i < len(nums) and nums[i] < 0:
            i += 1
        nums1 = []
        for j in range(i-1,-1,-1):
            nums1.append(nums[j] * nums[j])
        nums2 = []
        for j in range(i, len(nums)):
            nums2.append(nums[j] * nums[j])
        i, j = 0, 0
        ans = []
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                ans.append(nums1[i])
                i += 1
            else:
                ans.append(nums2[j])
                j += 1
        while i < len(nums1):
            ans.append(nums1[i])
            i += 1
        while j < len(nums2):
            ans.append(nums2[j])
            j += 1
        return ans