class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);
        int m=nums1.size(),n=nums2.size();
        int l=0,r=m;
        while(l<=r)
        {
            int p1 = (l+r)/2;
            int p2 = (n+m+1)/2 - p1;
            int ml1 = (p1==0) ? INT_MIN : nums1[p1-1];
            int mr1 = (p1==m) ? INT_MAX : nums1[p1];
            int ml2 = (p2==0) ? INT_MIN : nums2[p2-1];
            int mr2 = (p2==n) ? INT_MAX : nums2[p2];
            if(ml1<=mr2 && ml2<=mr1)
            {
                if((m+n)&1)return max(ml1,ml2)*1.0;
                else return 1.0*(max(ml1,ml2)+min(mr1,mr2))/2;
            }
            else if(ml1>mr2) r=p1-1;
            else l=p1+1;
        }
        return 0.0;
    }
};
