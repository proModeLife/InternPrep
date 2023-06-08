// https://leetcode.com/problems/plus-one

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits[-1]= (digits[-1]+1)%10
        carry=digits[-1]==0
        for i in range(len(digits)-2,-1,-1):
            if carry:
                digits[i]= (digits[i]+1)%10
                carry=digits[i]==0
        if carry:
            digits= [1]+digits
        return digits

