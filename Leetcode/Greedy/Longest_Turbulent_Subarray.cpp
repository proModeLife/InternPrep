class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size()<2)return arr.size();
        bool inc= arr[1]>arr[0];
        int count = arr[0]!=arr[1]?2:1;
        int ans=count;
        for(int i=2;i<arr.size();i++)
        {
            if((inc && arr[i]<arr[i-1]) ||( !inc && arr[i]>arr[i-1]))
            {
                count++;
            }
            else
            {
                count = arr[i]!=arr[i-1]?2:1;
            }
            ans=max(ans,count);
            inc = arr[i]>arr[i-1];
        }
        ans = max(count , ans);
        return ans;
    }
};
