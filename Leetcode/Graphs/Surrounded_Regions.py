class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        visited=set()
        def dfs(i,j):
            if i<0 or j<0 or i==len(board) or j==len(board[0]) or board[i][j]!='O' or (i,j) in visited:
                return
            visited.add((i,j))
            dfs(i+1,j)
            dfs(i-1,j)
            dfs(i,j+1)
            dfs(i,j-1)
        
        for i in range(len(board)):
            if board[i][0] == 'O' and (i,0) not in visited:
                dfs(i,0)
            if board[i][len(board[0])-1] == 'O' and (i,len(board[0])-1) not in visited:
                dfs(i,len(board[0])-1)
        for j in range(len(board[0])):
            if board[0][j] == 'O' and (0,j) not in visited:
                dfs(0,j)
            if board[len(board)-1][j] == 'O' and (len(board)-1,j) not in visited:
                dfs(len(board)-1,j)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]=='O' and (i,j) not in visited:
                    board[i][j]='X'



