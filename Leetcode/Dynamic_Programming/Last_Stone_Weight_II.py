class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        dp = {0}

        for s in stones:
            new_dp = set()
            for d in dp:
                new_dp.add(abs(d - s))
                new_dp.add(d + s)
            dp = new_dp

        print(dp)
        return min(dp)
        
