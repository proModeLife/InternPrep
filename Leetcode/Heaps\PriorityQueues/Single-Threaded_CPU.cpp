class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue< array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
        priority_queue< array<int,2>,vector<array<int,2>>,greater<array<int,2>>> rq;
        long long curr_dead=0;
        for(int i=0;i<tasks.size();i++)
        {
            pq.push({tasks[i][0],tasks[i][1],i});
        }
        vector<int> ans;
        while(pq.size() || rq.size())
        {
            if(rq.size())
            {
                array<int,2> t= rq.top();rq.pop();
                ans.push_back(t[1]);
                curr_dead+=t[0];
                while(pq.size() && pq.top()[0]<=curr_dead)
                {
                    array<int, 3> j = pq.top();pq.pop();
                    rq.push({j[1],j[2]});
                }
                continue;
            }
            if(pq.size())
            {
                array<int, 3> j = pq.top();pq.pop();
                curr_dead=j[0];
                rq.push({j[1],j[2]});
            }
        }
        return ans;
    }
};
