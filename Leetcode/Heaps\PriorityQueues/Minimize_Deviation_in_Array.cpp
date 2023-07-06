class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
        int res=INT_MAX, min_n=INT_MAX;
        priority_queue<int> pq;
        for(int num:nums)
        {
            if(num&1)num<<=1;
            min_n=min(min_n,num);
            pq.push(num);
        }
        while(!(pq.top()&1))
        {
            int curr = pq.top();
            pq.pop();
            res=min(res,curr-min_n);
            curr>>=1;
            min_n=min(min_n,curr);
            pq.push(curr);
        }
        return min(res,pq.top()-min_n);
    }
};
