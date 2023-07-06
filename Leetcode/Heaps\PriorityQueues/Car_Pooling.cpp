class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> p1;
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> p2;
        for(vector<int>& curr: trips )
        {
            p1.push({curr[1],curr[2],curr[0]});
        }
        long long current=0;
        while(p1.size())
        {
            while(p2.size() && p2.top()[0]<=p1.top()[0])
            {
                current-=p2.top()[2];
                p2.pop();
            }
            array<int,3> curr = p1.top();p1.pop();
            if(current+curr[2]>capacity)return false;
            else
            {
                p2.push({curr[1],curr[0],curr[2]});
                current+=curr[2];
            }
        }
        return true;
    }
};
