// https://leetcode.com/problems/coin-change

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        if(amount ==0) return 0;
        int n= coins.size();
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);

        for(int t=0; t<=amount;t++){
            if(t % coins[0]==0) {prev[t]= t/coins[0];} 
            else{prev[t]= 1e9;}
        }
        for(int ind=1; ind<n;ind++){
            for(int t=0; t<=amount;t++){
                int notTake= prev[t];
                int Take= INT_MAX;
                if(coins[ind]<=t){
                Take= 1+ curr[t-coins[ind]];
                    }
                curr[t]=min (notTake,Take);
            }
            prev=curr;
        }
        
        int ans=curr[amount];
        if(ans>=1e9) return -1;
        else return ans;
        
    }
};