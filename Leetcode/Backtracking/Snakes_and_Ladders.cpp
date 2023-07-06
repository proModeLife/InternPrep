class Solution {
public:
    int n;
    pair<int,int> pos (int x) {
        int r = (x-1) / n;
        int c = (x-1) % n;
        if (r&1)c = (n-1)-c;
        r = (n-1)-r;
        return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        n =board.size();
        vector<int> dist(n*n+1,-1);
        queue<int> q;
        dist[1]=0;
        q.push(1);
        while (!q.empty()&& dist.back()==-1)
        {
            int curr=q.front();q.pop();
            for(int next=curr+1;next<=min(curr+6,n*n);next++)
            {
                auto [row,column]=pos(next);
                int dest = board[row][column]==-1? next : board[row][column];
                if(dist[dest]==-1)
                {
                    dist[dest]=dist[curr]+1;
                    q.push(dest);
                }
            }
        }
        return dist[n*n];
    }
};
