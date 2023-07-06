class Solution {
public:

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
        [](vector<int> &a,vector<int> &b){return a[0] < b[0] || (a[0]==b[0] && a[1]>b[1]);});
        int ans=0;
        int i=0;
        int n=intervals.size();
        while(i<n)
        {
            ans++;
            vector<int> curr = intervals[i];
            i++;
            while(i<n && intervals[i][0]>=curr[0] && intervals[i][1]<= curr[1])i++;
        }
        return ans;
    }
};
