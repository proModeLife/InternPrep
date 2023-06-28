class Solution:
    def lengthOfLastWord(self, s: str) -> int:
            s = s.rstrip()
            last_word_length = 0
            for i in range(len(s) - 1, -1, -1):
                if s[i] == ' ':
                    break
                else:
                    last_word_length += 1
            return last_word_length