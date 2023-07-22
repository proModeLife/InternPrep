class Solution {
public:
    int ans=0;
    int count[26]={};
    int curr=0;
    void solve(int idx,vector<string>& arr)
    {
        if(idx==arr.size())return;
        for(int i=0;i<arr[idx].size();i++)
        {
            if(count[arr[idx][i]-'a'])
            {
                for(int j=i-1;j>=0;j--){count[arr[idx][j]-'a']--;curr--;}
                solve(idx+1,arr);
                return;
            }
            count[arr[idx][i]-'a']++;
            curr++;
        }
        ans=max(ans,curr);
        solve(idx+1,arr);
        for(int i=0;i<arr[idx].size();i++)
        {
            count[arr[idx][i]-'a']--;
            curr--;
        }
        solve(idx+1,arr);
    }
    int maxLength(vector<string>& arr) {
        solve(0,arr);
        return ans;
    }
};
