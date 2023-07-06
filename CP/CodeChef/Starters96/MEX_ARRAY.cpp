#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> f(n+2);
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        f[x]++;
	    }
	    vector<int> ans;
	    while(f[0])
	    {
	        int i=0;
	        for(;f[i]>0;i++)f[i]--;
	        ans.push_back(i);
	    }
	    int sum=0;
	    for(int i=0;i<=n+1;i++)sum+=f[i];
	    for(int i=0;i<sum;i++)ans.push_back(0);
	    cout<<ans.size()<<endl;
	    for(int it:ans)cout<<it<<" ";
	    cout<<endl;
	}
	return 0;
}