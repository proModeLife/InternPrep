class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        for(int i=num.size()-1;i>=0;i--)
        {
            num[i]+=k%10;
            k/=10;
            k+=num[i]/10;
            num[i]%=10;
            ans.push_back(num[i]);
        }
        while(k){ans.push_back(k%10);k/=10;}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
