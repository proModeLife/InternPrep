
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int large = n * n;
        if (n == 1)
            return 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({grid[0][0], 0});
        
        while (!pq.empty()) {
            pair<int, int> u = pq.top();
            pq.pop();
            
            ans = max(ans, u.first);
            if (u.second == n * n - 1)
                return ans;
            
            int row = u.second / n;
            int col = u.second % n;
            
            if (row > 0 && grid[row - 1][col] != large) {
                pq.push({grid[row - 1][col], u.second - n});
                grid[row - 1][col] = large;
            }
            if (row < n - 1 && grid[row + 1][col] != large) {
                pq.push({grid[row + 1][col], u.second + n});
                grid[row + 1][col] = large;
            }
            if (col > 0 && grid[row][col - 1] != large) {
                pq.push({grid[row][col - 1], u.second - 1});
                grid[row][col - 1] = large;
            }
            if (col < n - 1 && grid[row][col + 1] != large) {
                pq.push({grid[row][col + 1], u.second + 1});
                grid[row][col + 1] = large;
            }
        }
        
        return ans;
    }
};
