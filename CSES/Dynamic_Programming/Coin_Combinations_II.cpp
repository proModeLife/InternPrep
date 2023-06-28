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
    int mod=1e9+7;
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int> > dp(n+1,vector<int>(x+1,0));
    dp[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=x;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(arr[i-1]<=j)
            {
                (dp[i][j]+=dp[i][j-arr[i-1]])%=mod;
            }
        }
    }
    cout<<dp[n][x]<<endl;

	return 0;
}
