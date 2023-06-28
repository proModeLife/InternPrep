class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mxp=prices[0]
        mnp=prices[0]
        profit=0
        for price in prices:
            if price < mxp:
                profit+=mxp-mnp
                mxp=price
                mnp=price
            elif price> mxp:
                mxp=price
        return profit+mxp-mnp

