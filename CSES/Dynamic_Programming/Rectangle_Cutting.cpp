#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <iomanip>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your code here
      int w, h;
      cin >> w >> h;
      vector<vector<int>> dp(w+1,vector<int>(h+1));
      for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
          if (i == j) {
        dp[i][j] = 0;
          } else {
        dp[i][j] = 1e9;
        for (int k = 1; k < i; k++) {
          dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
        }
        for (int k = 1; k < j; k++) {
          dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
        }
          }
        }
      }
      cout << dp[w][h] << endl;

	return 0;
}
