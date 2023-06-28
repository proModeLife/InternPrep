class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s)<len(p):
            return []
        result=[]
        p_counter = [0] * 26
        window_counter = [0] * 26
        
        for c in p:
            p_counter[ord(c) - ord('a')] += 1
        
        for c in s[:len(p)]:
            window_counter[ord(c) - ord('a')] += 1
        
        for i in range(len(p), len(s)):

            if window_counter == p_counter:
                result.append(i - len(p))
            

            window_counter[ord(s[i - len(p)]) - ord('a')] -= 1
            window_counter[ord(s[i]) - ord('a')] += 1
        

        if window_counter == p_counter:
            result.append(len(s) - len(p))
        
        return result