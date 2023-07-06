#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x,k,p;
	    cin>>n>>x>>k>>p;
	    long long ans=p;
	    if(k)
	    {
	        ans+=min(x,k)*10;
	        k-=min(x,k);
	        if(k)
	        {
	            ans+=min(k,n-x-1)*5;
	            k-=min(k,n-x-1);
	            if(k)ans+=25;
	        }
	        
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
