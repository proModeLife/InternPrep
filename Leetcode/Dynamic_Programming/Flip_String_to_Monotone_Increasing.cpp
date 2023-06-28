class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> pre;
        int curr=0;
        for (int i=0;i<s.size();i++)
        {
            if(s[i]=='1')curr++;
            pre.push_back(curr);
        }
        curr=0;
        int ans=s.size();
        for (int i=s.size()-1;i>=0;i--)
        {
            ans=min(pre[i]+curr,ans);
            if(s[i]=='0')curr++;
        }
        ans=min(ans,curr);
        return ans;
    
    }
};
