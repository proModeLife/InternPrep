// https://leetcode.com/problems/hand-of-straights

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        count = defaultdict(int)
        for h in hand:
            count[h] += 1

        while count:
            min_card = min(count.keys())
            for i in range(min_card, min_card + groupSize):
                if count[i] == 0:
                    return False
                count[i] -= 1
                if count[i] == 0:
                    del count[i]

        return True
