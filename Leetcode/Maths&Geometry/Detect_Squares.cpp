
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

class DetectSquares {
public:
    unordered_map<int, vector<int>> xPoints;
    int cnt[1001][1001] = {};

    DetectSquares() {}

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        xPoints[x].push_back(y);
        cnt[x][y]++;
    }

    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int ans = 0;

        for (int y2 : xPoints[x1]) {
            if (y2 == y1) continue; // Skip empty square
            int sideLen = abs(y2 - y1);

            // Case: p3, p4 points are in the left side
            int x3 = x1 - sideLen, y3 = y2;
            int x4 = x1 - sideLen, y4 = y1;
            if(x3>=0 && x4>=0)
            ans += cnt[x3][y3] * cnt[x4][y4];

            // Case 2: p3, p4 points are in the right side
            x3 = x1 + sideLen, y3 = y2;
            x4 = x1 + sideLen, y4 = y1;
            if(x3<=1000 && x4<=1000)
            ans += cnt[x3][y3] * cnt[x4][y4];
        }

        return ans;
    }
};
