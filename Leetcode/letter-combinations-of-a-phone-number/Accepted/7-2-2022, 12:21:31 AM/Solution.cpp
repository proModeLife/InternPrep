// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
     vector<string> letterCombinations(string digits) {
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    
    vector<string> res;
    for(char ch: digits) {
        string chars = pad[ch - '0'];
        if(res.size() == 0) {
            for(char it: chars) {
                string temp = " ";
                temp[0] = it;
                res.push_back(temp);
            }
        } else {
            vector<string> newRes;
            for(string old: res) {
                for(char it: chars) {
                    string temp = old + it;
                    newRes.push_back(temp);
                }
            }
            res = newRes;
        }
    }
    
    return res;}
};