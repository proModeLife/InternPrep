class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) 
    {
        vector<int> res(queries.size(), -1);
        sort(intervals.begin(), intervals.end(), 
                    [](const auto &a, const auto &b) 
                    { return a[1] - a[0] < b[1] - b[0]; });
        set<pair<int, int>> s;
        for (int i = 0; i < queries.size(); ++i)
            s.insert({queries[i], i});
        for (auto &i : intervals) 
        {
            auto it = s.lower_bound({i[0], 0});
            while (it != end(s) && it->first <= i[1]) 
            {
                res[it->second] = i[1] - i[0] + 1;
                s.erase(it++);
            }
        }
        return res;
    }
};
