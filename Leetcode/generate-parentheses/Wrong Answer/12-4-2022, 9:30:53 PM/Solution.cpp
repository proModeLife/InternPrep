// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==1){
            vector<string> ans;
            ans.push_back("()");
            return ans;
        }
        else{
            vector<string> ans0= generateParenthesis(n-1);
            vector<string> ans1;
            for(auto it: ans0){
                string elem1= "()"+it;
                if(it+"()"!=elem1){
                    ans1.push_back(it+"()");
                }
                string elem2="("+it+")";
                ans1.push_back(elem1);
                ans1.push_back(elem2);
            }
            return ans1;
        }
    }
};