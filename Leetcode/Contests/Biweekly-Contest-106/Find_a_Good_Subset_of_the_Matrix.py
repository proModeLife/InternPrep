class Solution:
    def goodSubsetofBinaryMatrix(self, grid: List[List[int]]) -> List[int]:
        vals=[-1]*32
        for r in range(len(grid)):
            val=0
            for c in range(len(grid[0])):
                val+=grid[r][c]*2**c
            if val==0: return [r]
            vals[val]=r
        for i in range(len(vals)):
            if vals[i]!=-1:
                for j in range(i+1,len(vals)):
                    if vals[j]!=-1 and i&j == 0:
                        res=[vals[i],vals[j]]
                        res.sort()
                        return res
        return []
        