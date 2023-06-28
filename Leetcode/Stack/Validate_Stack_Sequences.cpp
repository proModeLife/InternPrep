class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        stack<int> stk;
        while (i<pushed.size() &&  j<popped.size())
        {
            stk.push(pushed[i]);
            i++;
            while(stk.size() && j<popped.size() && stk.top()==popped[j])
            {
                stk.pop();
                j++;
            }
        }
        return i==pushed.size() && j==popped.size();
    }
};
