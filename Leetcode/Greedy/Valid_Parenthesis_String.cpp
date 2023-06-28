class Solution {
public:
    bool checkValidString(string s)
    {
        int count =0;
        int stars =0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')count++;
            if(s[i]=='*')stars++;
            if(s[i]==')')
            {
                if(count==0)
                {
                    if(stars==0)return false;
                    stars--;
                }
                else
                {
                    count--;
                }
            }
        }
        if(count>stars)return false;
        count =0;
        stars =0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==')')count++;
            if(s[i]=='*')stars++;
            if(s[i]=='(')
            {
                if(count==0)
                {
                    if(stars==0)return false;
                    stars--;
                }
                else
                {
                    count--;
                }
            }
        }
        if(count>stars)return false;
        return true;
    }
};
