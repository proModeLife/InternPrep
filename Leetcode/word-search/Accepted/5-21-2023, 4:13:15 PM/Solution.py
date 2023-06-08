// https://leetcode.com/problems/word-search

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        R = len(board)
        C = len(board[0]) 
        # if len of word is greater than total number of character in board
        if len(word) > R*C:
            return False
        # print(sum(board, []))
        # used to concatinate the elementes of the board instead of summing it
        count = Counter(sum(board, []))
        # print(count)
        # count of a LETTER in word is Greater than count of it being in board
        for c, countWord in Counter(word).items():
            if count[c] < countWord:
                return False  
        # if count of 1st letter of Word(A) is Greater than that of Last One in Board(B). 
        # Reverse Search the word then search as less case will be searched.
        if count[word[0]] > count[word[-1]]:
             word = word[::-1]            
        # simple backtracking 
        seen = set()    # so we dont access the element again
        
        def dfs(r, c, i):
            if i == len(word):
                return True
            if r < 0 or c < 0 or r >= R or c >= C or word[i] != board[r][c] or (r,c) in seen:
                return False
            seen.add((r,c))
            res = (
                dfs(r+1,c,i+1) or 
                dfs(r-1,c,i+1) or
                dfs(r,c+1,i+1) or
                dfs(r,c-1,i+1) 
            )
            seen.remove((r,c))  #backtracking
            return res
        for i in range(R):
            for j in range(C):
                if dfs(i,j,0):
                    return True
        return False