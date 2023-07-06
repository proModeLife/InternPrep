class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int> curr;
        vector<vector<int>> ans;
        int i=0,n=intervals.size();
        while(i<n){
            curr= intervals[i];
            i++;
            while(i<n && curr[1]>=intervals[i][0])
            {
                curr[1]=max(curr[1],intervals[i][1]);
                i++;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};
