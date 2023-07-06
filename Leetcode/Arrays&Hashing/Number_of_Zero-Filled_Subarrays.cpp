class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i=0;
        long long ans=0;
        while(i<nums.size())
        {
            if(nums[i]==0)
            {
                long long start=i;
                while(i<nums.size()&&nums[i]==0)i++;
                long long end=i;
                ans+=(end-start)*(end-start+1)/2;
            }
            else i++;
        }
        return ans;
    }
};
