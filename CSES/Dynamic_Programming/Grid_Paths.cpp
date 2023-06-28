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
    int mod=1e9+7;
    vector<string > grid(n);
    vector<int> curr(n+1,0);
    vector<int> prev(n+1,0);
    for(int i=0;i <n; i++)
    {
        cin>>grid[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        if(grid[n-1][i]=='*')break;
        curr[i]=1;
    }
    prev=curr;
    for(int i=n-2;i>=0;i--)
    {
        curr.assign(n+1,0);
        for(int j=n-1;j>=0;j--)
        {
            if(grid[i][j]=='.')
            {
                (curr[j]=curr[j+1]+prev[j])%=mod;
            }
        }
        prev=curr;
    }
    cout<<curr[0]<<endl;
	return 0;
}
