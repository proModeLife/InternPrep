class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        q=deque()
        zeroes=0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    q.append((0,i,j))
                else:
                    zeroes+=1
        if zeroes==0 or not q: return -1
        while q:
            c,i,j=q.popleft()
            if i>0 and grid[i-1][j]==0:
                if zeroes==1: return c+1
                else:
                    zeroes-=1
                    grid[i-1][j]=1
                    q.append((c+1,i-1,j))
            if j>0 and grid[i][j-1]==0:
                if zeroes==1: return c+1
                else:
                    zeroes-=1
                    grid[i][j-1]=1
                    q.append((c+1,i,j-1))
            if i<len(grid)-1 and grid[i+1][j]==0:
                if zeroes==1: return c+1
                else:
                    zeroes-=1
                    grid[i+1][j]=1
                    q.append((c+1,i+1,j))
            if j<len(grid[0])-1 and grid[i][j+1]==0:
                if zeroes==1: return c+1
                else:
                    zeroes-=1
                    grid[i][j+1]=1
                    q.append((c+1,i,j+1))
        
        
