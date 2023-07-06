
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        
        for (const auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }
        
        vector<string> ans;
        stack<string> st;
        st.push("JFK");
        
        while (!st.empty()) {
            string src = st.top();
            
            if (adj[src].empty()) {
                ans.push_back(src);
                st.pop();
            } else {
                string dest = adj[src].top();
                adj[src].pop();
                st.push(dest);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;    
    }
};
