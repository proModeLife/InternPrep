class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        l, r = max(weights), sum(weights)
        
        def canShip(capacity: int) -> bool:
            days_needed = 1
            current_weight = 0
            
            for weight in weights:
                current_weight += weight
                if current_weight > capacity:
                    current_weight = weight
                    days_needed += 1
                    if days_needed > days:
                        return False
            
            return True
        
        while l < r:
            mid = (l + r) // 2
            if canShip(mid):
                r = mid
            else:
                l = mid + 1
        
        return l