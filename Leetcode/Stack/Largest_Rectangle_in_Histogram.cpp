class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n= heights.size();
        if(!n)return 0;
        vector<int> left(n),right(n);
        right[n-1]=n;left[0]=-1;
        for(int i=1;i<n;i++)
        {
            int j = i-1;
            while(j>=0 && heights[j]>=heights[i])j=left[j];
            left[i]=j;
        }
        for(int i=n-2;i>=0;i--)
        {
            int j = i+1;
            while(j<n && heights[j]>=heights[i])j=right[j];
            right[i]=j;
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max((int)ans,heights[i]*(-left[i]+right[i]-1));
        }
        return ans;
    }
};
