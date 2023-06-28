class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        vector<long long> pref(s.size(),1);
        pref[minJump]= s[minJump]=='0'?2:1;
        int i=minJump+1;
        while(i<s.size())
        {
            pref[i]=pref[i-1];
            if(s[i]=='0')
            {
                if(i<maxJump+1 || pref[i-minJump]!=pref[max(i-maxJump-1,0)])
                {
                    pref[i]++;
                }
            }
            i++;
        }
        return pref[s.size()-1] != pref[s.size()-2];
    }
};
