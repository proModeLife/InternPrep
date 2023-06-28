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
    int arr[n];
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    vector<vector<long long>> dp(n,vector<long long>(n,0));
    for(int l=n-1;l>=0;l--){
        for(int r=l;r<n;r++){
            if(l==r)dp[l][l]=arr[l];
            else{
                dp[l][r]=max(arr[l]-dp[l+1][r],
                        arr[r]-dp[l][r-1]);
            }
        }
    }
    cout<<(sum+dp[0][n-1])/2<<endl;

	return 0;
}
