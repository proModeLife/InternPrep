class Solution {
public:
    vector<int> preSum;
    bool possible(int limit,int k,vector<int>& nums)
    {
        int count =0;
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]+sum>limit)
            {
                count++;
                sum=nums[i];
            }
            else sum+=nums[i];
        }
        return count<k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=0,r=0;
        for(int num:nums)
        {
            l=max(l,num);
            r+=num;
        }
        while(l<r)
        {
            int mid = (l+r)/2;
            if(possible(mid,k,nums))r=mid;
            else l=mid+1;
        }
        return l;

    }
};
