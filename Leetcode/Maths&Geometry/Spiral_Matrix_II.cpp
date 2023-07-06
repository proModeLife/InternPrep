
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));

        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int curr = 1;

        while (curr <= n * n) {
            for (int j = left; j <= right; j++) {
                ans[top][j] = curr++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                ans[i][right] = curr++;
            }
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans[bottom][j] = curr++;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = curr++;
                }
                left++;
            }
        }
        return ans;
    }
};
