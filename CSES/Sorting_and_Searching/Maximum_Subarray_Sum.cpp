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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your code here
    int n;
    cin>>n;
    long long curr=INT_MIN,ans=INT_MIN;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(curr>=0)curr=curr+t;
        else curr=t;
        if(curr>ans)ans=curr;
    }
    cout<<ans<<endl;
	return 0;
}
