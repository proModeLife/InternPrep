class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        def find(spell):
            l,r=0,len(potions)-1
            while l<r:
                m=(l+r)//2
                if spell*potions[m]<success:l=m+1
                else: r=m
            return len(potions)-l if l!=len(potions)-1 else int(spell*potions[-1]>=success)
        return [find(s) for s in spells]