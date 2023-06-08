// https://leetcode.com/problems/length-of-last-word

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
            # Strip any trailing spaces from the string
            s = s.rstrip()
            
            # Initialize a variable to keep track of the length of the last word
            last_word_length = 0
            
            # Iterate over the string characters in reverse order
            for i in range(len(s) - 1, -1, -1):
                if s[i] == ' ':
                    # If we encounter a space, we've reached the end of the last word
                    break
                else:
                    # If we encounter a non-space character, increment the last word length
                    last_word_length += 1
            
            # Return the length of the last word
            return last_word_length