class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        left, right = 0, 0
        a = fruits[0]
        b = None
        ans = 0
        while right < len(fruits) and fruits[right] == a:
            right += 1
        if right == len(fruits):
            return len(fruits)
        else:
            b = fruits[right]
        while right < len(fruits):
            while right < len(fruits) and (fruits[right] == a or fruits[right] == b):
                right += 1
            ans = max(ans, right - left)
            if right < len(fruits):
                b = fruits[right]
                a = fruits[right - 1]
                left = right - 1
                while fruits[left] == a:
                    left -= 1
                left += 1
        return ans
