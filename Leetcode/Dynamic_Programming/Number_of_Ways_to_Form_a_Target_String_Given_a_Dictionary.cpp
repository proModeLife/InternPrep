class Solution {
public:
    const int mod = 1e9+7;
    int numWays(vector<string>& words, string target) 
    {
        vector<vector<long long>> dp(words[0].size()+1,
vector<long long>(target.size()+1));
        for(int i=0;i<=words[0].size();i++)dp[i][target.size()]=1;
        vector<vector<int>> charCount (words[0].size(),vector<int>(26));
        for(int i=0;i<words[0].size();i++)
            for(int j=0;j<words.size();j++)
                charCount[i][words[j][i]-'a']++;
        for(int i=words[0].size()-1;i>=0;i--)
            for(int j=target.size()-1;j>=0;j--)
            {
                dp[i][j]=dp[i+1][j];
                if(charCount[i][target[j]-'a'])
                {
                    (dp[i][j]+= dp[i+1][j+1]*charCount[i][target[j]-'a'])%=mod;
                }
            }
        return dp[0][0];
    }
};
