
class Solution {
public:
    const int mod = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> engineers;
        for (int i = 0; i < n; i++) {
            engineers.push_back({efficiency[i], speed[i]});
        }
        
        sort(engineers.rbegin(), engineers.rend());
        
        long long maxPerformance = 0;
        long long totalSpeed = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < n; i++) 
        {
            totalSpeed += engineers[i].second;
            pq.push(engineers[i].second);
            
            if (pq.size() > k) 
            {
                totalSpeed -= pq.top();
                pq.pop();
            }
            
            long long currPerformance = totalSpeed * engineers[i].first;
            maxPerformance = max(maxPerformance, currPerformance);
        }
        
        return maxPerformance % mod;
    }
};
