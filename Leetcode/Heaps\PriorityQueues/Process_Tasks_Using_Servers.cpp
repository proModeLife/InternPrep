

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> ps;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> ws;
        
        for (int i = 0; i < servers.size(); i++) {
            ps.push({servers[i], i});
        }
        
        vector<int> ans;
        queue<int> waiting;
        int curr = 0;
        
        for (int i = 0; i < tasks.size(); i++) {
            curr = max(curr, i); 
            while (!ws.empty() && ws.top()[0] <= curr) {
                array<int, 2> s = ws.top();
                ws.pop();
                ps.push({servers[s[1]], s[1]});
            }
            if (!ps.empty()) {
                while (!ps.empty() && !waiting.empty()) {
                    int j = waiting.front();
                    waiting.pop();
                    
                    array<int, 2> s = ps.top();
                    ps.pop();
                    
                    ans.push_back(s[1]);
                    ws.push({curr + tasks[j], s[1]});
                }
                
                if (!ps.empty()) {
                    array<int, 2> s = ps.top();
                    ps.pop();
                    
                    ans.push_back(s[1]);
                    ws.push({curr + tasks[i], s[1]});
                } else {
                    waiting.push(i);
                }
            } else {
                waiting.push(i);
            }
        }
        
        // Process remaining tasks
        while (!waiting.empty()) {
            curr = max(curr, ws.top()[0]);
            
            while (!ws.empty() && ws.top()[0] <= curr) {
                array<int, 2> s = ws.top();
                ws.pop();
                ps.push({servers[s[1]], s[1]});
            }
            
            while (!ps.empty() && !waiting.empty()) {
                int j = waiting.front();
                waiting.pop();
                
                array<int, 2> s = ps.top();
                ps.pop();
                
                ans.push_back(s[1]);
                ws.push({curr + tasks[j], s[1]});
            }
        }
        
        return ans;
    }
};
