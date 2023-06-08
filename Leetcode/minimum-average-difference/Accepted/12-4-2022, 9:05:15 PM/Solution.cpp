// https://leetcode.com/problems/minimum-average-difference

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int lastSum=0,iniSum=0,ans=0,mindiff=1e9;
        int n = nums.size();
        if(n==1) return 0;
        for (int i=0;i<n;i++){
            lastSum+=nums[i];
        }
        for (int i=0;i<n;i++){
            lastSum-=nums[i];
            iniSum+=nums[i];
            long long int diff;
            if(i==n-1){
                diff= abs(round(iniSum/(i+1)));
            }
            else{
                diff= abs(round(iniSum/(i+1))-round(lastSum/(n-i-1)));
            }
                
            if(mindiff>diff){
                mindiff=diff;
                ans=i;
            }
        }
        return ans;
    }
};