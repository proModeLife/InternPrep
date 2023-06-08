// https://leetcode.com/problems/search-a-2d-matrix

from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])
        
        if n == 0 or target < matrix[0][0] or target > matrix[n-1][m-1]:
            return False 
        
        l = 0
        r = m - 1
        
        if n == 1:
            while l <= r:
                g = (r + l) // 2
                if matrix[0][g] < target:
                    l = g + 1
                elif matrix[0][g] > target:
                    r = g - 1
                else:
                    return True
            return False 
        
        else:
            mid = (n-1) // 2
            if matrix[mid][0] <= target <= matrix[mid][m-1]:
                return self.searchMatrix(matrix[mid:mid+1], target)
            elif target < matrix[mid][0]:
                return self.searchMatrix(matrix[:mid], target)
            else:
                return self.searchMatrix(matrix[mid+1:], target)
