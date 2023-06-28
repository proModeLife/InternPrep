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
long long dp[1000002][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your code here
    int mod=1e9+7;
    dp[1][0]=dp[1][1]=1;
    for(int i=1;i<=1000000;i++){
        dp[i][0]%=mod;
        dp[i][1]%=mod;
        dp[i+1][0]=2*dp[i][0];
        dp[i+1][1]=dp[i][0];
        dp[i+1][0]+=dp[i][1];
        dp[i+1][1]+=4*dp[i][1];
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n][0]+dp[n][1])%mod<<endl;
    }

	return 0;
}
