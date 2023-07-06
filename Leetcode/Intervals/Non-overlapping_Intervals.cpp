
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int ans=0;
        int i=0;
        while(i<n)
        {
            vector<int> curr= intervals[i];
            i++;
            while(i<n && curr[1]>intervals[i][0])
            {
                curr[1]=min(curr[1],intervals[i][1]);
                i++;
                ans++;
            }
        }
        return ans;
    }
};
