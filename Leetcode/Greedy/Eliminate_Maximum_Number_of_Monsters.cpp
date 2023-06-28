class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> times;
        for(int i=0;i<dist.size();i++)
        {
            times.push_back((double)dist[i]/speed[i]);
        }
        sort(times.begin(),times.end());
        int currtime=0,ans=0;
        for(int i=0;i<dist.size();i++)
        {
            if(currtime<times[i])
            {
                currtime++;
                ans++;
            }
            else break;
        }
        return ans;
    }
};
