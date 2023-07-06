class Solution {
public:
    int partitionString(string s) {
        int j=0;
        int ans=0;
        while(j<s.size())
        {
            ans++;
            vector<bool>curr(26);
            while(j<s.size() && !curr[s[j]-'a'])
            {
                curr[s[j]-'a']=true;
                j++;
            }
        }
        return ans;
    }
};
