class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) { 
        vector<pair<long long, long long>> pairs;
        for (int i = 0; i < nums1.size(); i++) {
            pairs.push_back({nums1[i], nums2[i]});
        }
        sort(pairs.begin(), pairs.end(), [](const pair<long long, long long>& a, const pair<long long , long long>& b) {
            return a.second > b.second;
        });
        priority_queue<long long, vector<long long>, greater<long long>> top_k_heap;
        long long top_k_sum = 0;
        for (int i = 0; i < k; i++) {
            top_k_heap.push(pairs[i].first);
            top_k_sum += pairs[i].first;
        }
        long long answer = top_k_sum * pairs[k - 1].second;
        for (int i = k; i < nums1.size(); i++) {
            top_k_sum -= top_k_heap.top();
            top_k_heap.pop();
            top_k_sum += pairs[i].first;
            top_k_heap.push(pairs[i].first);
            answer = max(answer, top_k_sum * pairs[i].second);
        }
        
        return answer;
    }
};
