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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            if(a>b)ans++;
        }
        cout<<ans<<endl;
    }


	return 0;
}
