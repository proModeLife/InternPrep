
#include <stack>
#include <string>

class Solution {
public:
    string removeStars(string s) {
        vector<char> stk;
        for (char c : s) 
        {
            if (c == '*')
            {
                stk.pop_back();
            } else 
            {
                stk.push_back(c);
            }
        }
        return string(stk.begin(),stk.end());
    }
};
