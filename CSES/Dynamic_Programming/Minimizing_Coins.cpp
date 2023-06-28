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
    set<int> s;
    s.insert(0);
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(x+1,1e9);
    dp[0]=0;
    for (int i=0;i<=x;i++)
    {
        for (int j=0;j<n;j++)
        {
            if(i-arr[j]>=0){
                dp[i]=min(dp[i],dp[i-arr[j]]+1);
            }
        }
    }
    cout<<(dp[x]==1e9 ? -1 :dp[x])<<endl;

	return 0;
}
