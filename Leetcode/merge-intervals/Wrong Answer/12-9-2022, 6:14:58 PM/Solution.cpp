// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int> next = {0,0};
        vector<vector<int>> ans;
        int i=0,n=intervals.size();
        while(i<n){
            next= intervals[i];
            while(i<n && next[1]>=intervals[i][0]){i++;}
            next[1]=intervals[i-1][1];
            ans.push_back(next);
        }
        return ans;
    }
};