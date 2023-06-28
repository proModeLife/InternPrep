class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        
        # index of ticket
        _1day_pass, _7day_pass, _30day_pass = 0, 1, 2
        
        # set of travel days
        travel_days = set(days)
        
        # last travel day
        last_traverl_day = days[-1]
        
        # DP Table, record for minimum cost of ticket to travel
        dp_cost = [  0 for _ in range(last_traverl_day+1)]
    
        
        # Solve min cost by Dynamic Programming
        for day_i in range(1, last_traverl_day+1):
            
            
            if day_i not in travel_days:
                
                # today is not traveling day
                # no extra cost
                dp_cost[day_i] = dp_cost[day_i - 1]
            
            
            else:
                
                # today is traveling day
                # compute optimal cost by DP
                
                dp_cost[day_i] = min(   dp_cost[ day_i - 1 ]  + costs[ _1day_pass ],
                                        dp_cost[ max(day_i - 7, 0) ]  + costs[ _7day_pass ],
                                        dp_cost[ max(day_i - 30, 0) ] + costs[ _30day_pass ]     )
        
        
        # Cost on last travel day of this year is the answer
        return dp_cost[last_traverl_day]
        