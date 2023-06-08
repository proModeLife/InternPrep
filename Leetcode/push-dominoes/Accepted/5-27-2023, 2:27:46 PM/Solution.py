// https://leetcode.com/problems/push-dominoes

class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        dominoes = list(dominoes)  # Convert string to a list

        right, left = set(), set()
        for i in range(len(dominoes)):
            if dominoes[i] == 'R':
                right.add(i)
            if dominoes[i] == 'L':
                left.add(i)

        while left or right:
            nextRight, nextLeft = set(), set()
            for l in right:
                if l + 1 < len(dominoes) and dominoes[l + 1] == '.':
                    if l + 2 in left:
                        left.remove(l + 2)
                    else:
                        dominoes[l + 1] = 'R'
                        nextRight.add(l + 1)
            right = nextRight
            for r in left:
                if r - 1 >= 0 and dominoes[r - 1] == '.':
                    dominoes[r - 1] = 'L'
                    nextLeft.add(r - 1)
            left = nextLeft

        return ''.join(dominoes)  # Convert the list back to a string
