class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        vector<vector<int>> ranges (26,vector<int>(2,-1));
        for (int i=0;i<s.size();i++)
        {
            if(ranges[s[i]-'a'][0]==-1)ranges[s[i]-'a'][0]=i;
            ranges[s[i]-'a'][1]=i;
        }
        sort(ranges.begin(),ranges.end());
        vector<int> ans;
        for(int i=0;i<26;i++)
        {
            if(ranges[i][0]==-1)continue;
            for(int j=i+1;j<26;j++)
            {
                if(ranges[j][0]>ranges[i][1])break;
                ranges[i][1]=max(ranges[i][1],ranges[j][1]);
                ranges[j][0]=-1;
            }
            ans.push_back(-ranges[i][0]+ranges[i][1]+1);
        }
        return ans;
    }
};
