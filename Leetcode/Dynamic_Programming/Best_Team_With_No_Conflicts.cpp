class Solution 
{
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        vector<array<int,2>> ageScores;
        for(int i=0; i< scores.size(); i++)
            ageScores.push_back({ages[i],scores[i]});
        sort(ageScores.begin(), ageScores.end());
        vector<long long> dp (scores.size()+1);
        long long ans=0;
        for(int i=0; i< scores.size();i++)
        {
            dp[i]=ageScores[i][1];
            for(int j=0; j<i;j++)
            {
                if(ageScores[j][0]==ageScores[i][0] || ageScores[j][1] <= ageScores[i][1])
                    dp[i]=max(dp[i],dp[j]+ageScores[i][1]);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
