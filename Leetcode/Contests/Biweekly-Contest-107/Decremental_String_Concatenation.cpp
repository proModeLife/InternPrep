class Solution {
public:
    int dp[1001][27][27]={0};
    int solve(vector<string>& words, int i, char firstChar, char lastChar) 
    {
        if(i>=words.size()) return 0;
        if (dp[i][firstChar-'a'][lastChar-'a'])return dp[i][firstChar-'a'][lastChar-'a'];
        int res1,res2,wordSize=words[i].size();

        res1 = wordSize + solve(words,i+1,firstChar,words[i].back());
        if(lastChar==words[i][0])res1--;
        res2 = wordSize + solve(words,i+1,words[i][0],lastChar);
        if(firstChar==words[i].back())res2--;

        return dp[i][firstChar-'a'][lastChar-'a']= min(res1,res2);
    }
    int minimizeConcatenatedLength(vector<string>& words)
    {
        return words[0].size()+ solve(words,1,words[0][0],words[0].back());
    }
};