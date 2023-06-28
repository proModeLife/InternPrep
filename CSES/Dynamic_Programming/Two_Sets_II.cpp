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
    int mod=1e9+7;
    cin>>n;
    long long total= (n*(n+1))/2;
    if(total%2==1){
        cout<<0<<endl;
        return 0;
    }
    total>>=1;
    vector<int> dp(total+1,0);
    dp[0]=1;
   
    for(int i=1;i<n;i++){
        for(int j=total;j>=0;j--){
            if(dp[j] && (i+j<=total) ){
                
                (dp[i+j]+=dp[j])%=mod;
            }
        }
    }
    cout<<dp[total]<<endl;
    
	return 0;
}
