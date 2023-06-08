// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s)<len(p):
            return []
        result=[]
        p_counter = [0] * 26
        window_counter = [0] * 26
        
        # Initialize the counter for p
        for c in p:
            p_counter[ord(c) - ord('a')] += 1
        
        # Initialize the counter for the first window
        for c in s[:len(p)]:
            window_counter[ord(c) - ord('a')] += 1
        
        # Check each window for anagrams of p
        for i in range(len(p), len(s)):
            # Checkif the window is an anagram of p
            if window_counter == p_counter:
                result.append(i - len(p))
            
            # Slide the window by 1 position to the right
            window_counter[ord(s[i - len(p)]) - ord('a')] -= 1
            window_counter[ord(s[i]) - ord('a')] += 1
        
        # Check the last window for anagrams of p
        if window_counter == p_counter:
            result.append(len(s) - len(p))
        
        return result