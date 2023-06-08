// https://leetcode.com/problems/word-search

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        visited = [[False] * len(board[0]) for _ in range(len(board))]

        def dfs(i,j,curr):
            if curr==word:
                return True
            if len(curr)>=len(word) or curr!=word[:len(curr)]:
                return False

            a,b,c,d=False,False,False,False

            # Check up
            if i>0 and not visited[i-1][j]:
                visited[i-1][j]=True
                a=dfs(i-1,j,curr+board[i-1][j])

                visited[i-1][j]=False
                if a:
                    return True

            # Check left
            if j>0 and not visited[i][j-1]:
                visited[i][j-1]=True
                b=dfs(i,j-1,curr+board[i][j-1])
                visited[i][j-1]=False
                if b:
                    return True

            # Check down
            if i<len(board)-1 and not visited[i+1][j]:
                visited[i+1][j]=True
                c=dfs(i+1,j,curr+board[i+1][j])
                visited[i+1][j]=False
                if c:
                    return True

            # Check right
            if j<len(board[0])-1 and not visited[i][j+1]:
                visited[i][j+1]=True
                d=dfs(i,j+1,curr+board[i][j+1])
                visited[i][j+1]=False
                if d:
                    return True

            return False

        for i in range(len(board)):
            for j in range(len(board[0])):
                visited[i][j]=True
                if dfs(i,j,board[i][j]):
                    return True
                visited[i][j]=False

        return False