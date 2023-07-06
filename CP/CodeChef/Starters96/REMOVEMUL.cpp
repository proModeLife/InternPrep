#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long n,m;
	    cin>>n>>m;
	    vector<int> q(m);
	    long long ans=0;
	    for(int i=0;i<m;i++)
	    {
	        cin>>q[i];
	        ans-=q[i];
	    }
	    ans = ans + n*(n+1)/2; 
	    cout<<ans<<endl;
	}
	return 0;
}
