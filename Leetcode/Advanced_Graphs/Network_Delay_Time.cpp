class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n,(int)1e8);
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]-1].push_back({times[i][2],times[i][1]-1});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty())
        {
            pair<int,int> u = pq.top();pq.pop();
            if(u.first>dist[u.second])continue;
            for(pair<int,int>v : adj[u.second])
            {
                if(dist[v.second]>v.first+u.first)
                {
                    dist[v.second]=v.first+u.first;
                    pq.push({dist[v.second],v.second});
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)ans=max(ans,dist[i]);
        if(ans==(int)1e8)return -1;
        return ans;
    }
};
