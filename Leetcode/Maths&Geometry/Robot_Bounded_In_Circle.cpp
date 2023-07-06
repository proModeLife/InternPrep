
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int i = 1;
        int x = 0, y = 0;
        for (char c : instructions) {
            if (c == 'G') {
                x += dx[i];
                y += dy[i];
            } else if (c == 'L') {
                i = (i + 1) & 3;
            } else if (c == 'R') {
                i = (i + 3) & 3;
            }
        }
        return (x == 0 && y == 0) || i != 1;
    }
};
