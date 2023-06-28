class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize:
            return False
        count = defaultdict(int)
        for h in hand:
            count[h] += 1

        while count:
            min_card = min(count.keys())
            val = count[min_card]
            for i in range(min_card, min_card + groupSize):
                if count[i] < val:
                    return False
                count[i] -= val
                if count[i] == 0:
                    del count[i]

        return True
