
long long limit = 99999999999;
class Solution {
public:
    bool solve(string s, long long prev, int ind, int cnt) {
        if (ind == s.size()) 
            return cnt>1;
            long long num=0;
            for (int j = ind; j < s.size(); j++) {
                num=num*10l+s[j]-'0';
                if(num>limit)break;
                if ((num==prev-1 || prev==-1)&& solve(s, num, j + 1,cnt+1)) 
                    return true;
                if(num>prev && prev!=-1)break;
            }
        return false;
    }
    
    bool splitString(string s) {
        if(s.size()<=1)return false;
        return solve(s,-1,0,0);
    }
};


