class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        vector<pair<int,int>> vp;
        for(auto it:logs) vp.push_back({it[1],it[0]}); //time,serverid
        sort(vp.begin(),vp.end()); 
        int q = queries.size();
        unordered_map<int,int> mp;
        vector<int> ans(q,0);
        vector<pair<int,int>> time(q);
        for(int i = 0;i<q;i++) time[i] = {queries[i],i}; //time,index
        sort(time.begin(),time.end()); 
        int i = 0,j = 0; 
        for(auto tm:time)
        {
            int curtime = tm.first;
            int ind = tm.second;
            int start = max(0,curtime-x); 
            int end = curtime; 
            while(j<m and vp[j].first<=end) 
            {
                mp[vp[j].second]++; 
                j++;
            }
            while(i<m and vp[i].first<start) 
            {
                if(mp[vp[i].second]==1) mp.erase(vp[i].second); 
                else mp[vp[i].second]--;
                i++;
            }
            ans[ind] = n - mp.size();
        }
        return ans;
    }
};