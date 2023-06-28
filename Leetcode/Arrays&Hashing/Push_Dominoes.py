class Solution:
   def pushDominoes(self, d: str) -> str:
        tmp = ''
        while d != tmp:
            tmp = d
            d = d.replace('R.L', 'xxx')
            d = d.replace('R.', 'RR')     
            d = d.replace('.L', 'LL')

        return  d.replace('xxx', 'R.L')