class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        vector<char> vec;
        for(int i=0;i<num.size();i++)
        {
            while(k && vec.size() && vec.back()-'0'> num[i]-'0')
            {
                vec.pop_back();
                k--;
            }
            if(vec.size()==0 && num[i]=='0')continue;
            vec.push_back(num[i]);
        }
        while(k && vec.size())
        {
            vec.pop_back();
            k--;
        }
        if(vec.size())
        return string(vec.begin(),vec.end());
        else return "0";
    }
};
