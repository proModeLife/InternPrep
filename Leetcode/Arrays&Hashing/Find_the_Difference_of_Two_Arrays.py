class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        ans1 = list(set(i for i in nums1 if i not in nums2))
        ans2 = list(set(i for i in nums2 if i not in nums1))
        return [ans1, ans2]
