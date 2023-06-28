class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        ans=[0]*(len(arr)-1)+[-1]
        for i in range( len(arr) - 1, 0, -1) :
            ans[i-1]=max(ans[i],arr[i])
        return ans
