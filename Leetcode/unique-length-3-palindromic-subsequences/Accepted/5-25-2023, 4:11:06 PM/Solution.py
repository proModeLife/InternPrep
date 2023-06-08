// https://leetcode.com/problems/unique-length-3-palindromic-subsequences

class Solution:
    def countPalindromicSubsequence(self, string: str) -> int:
        letter_indices = defaultdict(list)
        
        # store the indices of each letter in the string
        for i, letter in enumerate(string):
            letter_indices[letter].append(i)
        
        count = 0
        for i in range(26):
            # get the letter we're currently checking
            current_letter = chr(ord("a") + i)
            if current_letter not in letter_indices:
                continue
            
            # get the range of indices between the first and last occurrence of the current letter
            left, right = letter_indices[current_letter][0] + 1, letter_indices[current_letter][-1] - 1
            if left > right:
                continue
            
            # check for palindromic subsequences that include the current letter
            for j in range(26):
                other_letter = chr(ord("a") + j)
                if other_letter in letter_indices:
                    # use binary search to find the first index of the other letter within the range
                    index = bisect.bisect_left(letter_indices[other_letter], left)
                    if index < len(letter_indices[other_letter]) and letter_indices[other_letter][index] <= right:
                        count += 1
        
        return count