#include <climits>
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
//int dp[int(1e6+1)]={INT_MAX-1};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your code here
    int n;
    cin>>n;
    vector<int> dp(n+1,INT_MAX-1);
    dp[0]=0;
    for(int i=1;i<10;i++)dp[i]=1;
    for(int i=10;i<=n;i++){
        int num=i;
        while(num>0){
            dp[i]=min(dp[i],dp[i-num%10]+1);
            num/=10;
        }
    }
    cout<<dp[n]<<endl;

	return 0;
}
