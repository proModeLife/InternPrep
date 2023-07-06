
class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < 8; i++) 
        {
            int count = 0;
            int x = rMove, y = cMove;
            while (x + dx[i] < n && x + dx[i] >= 0 && y + dy[i] < m && y + dy[i] >= 0 &&
                   board[x + dx[i]][y + dy[i]] == (color == 'W' ? 'B' : 'W')) 
                   {
                        x += dx[i];
                        y += dy[i];
                        count++;
                    }
                    x+=dx[i];
                    y+=dy[i];
            if (count >= 1 && x >= 0 && x < n && y >= 0 && y < m && board[x][y] == color)
                return true;
        }
        return false;
    }
};
