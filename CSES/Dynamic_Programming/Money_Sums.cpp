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
    int n;
    cin>>n;
    int sum=0;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    vector<bool> dp (sum+1,false);
    dp[0]=true;
    long long ans=0;
    
    for (int j=0;j<n;j++){
        for(int i=sum;i>=0;i--)
        {
            if(dp[i]&& !dp[i+arr[j]]){
                dp[i+arr[j]]=true;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=sum;i++){
        if(dp[i])cout<<i<<" ";
    }
    cout<<endl;
	return 0;
}
