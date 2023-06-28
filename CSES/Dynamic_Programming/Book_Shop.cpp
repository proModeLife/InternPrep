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
    int n,x;
    cin>>n>>x;
    int h[n],s[n];
    for(int i=0;i<n;i++)cin>>h[i];
    for(int i=0;i<n;i++)cin>>s[i];
    vector<vector<int> > dp(n+1,vector<int>(x+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j]=dp[i-1][j];
            if(h[i-1]<=j)
            {
                dp[i][j]=max(dp[i][j],s[i-1]+dp[i-1][j-h[i-1]]);
            }
        }
    }
    cout<<dp[n][x]<<endl;
	return 0;
}
