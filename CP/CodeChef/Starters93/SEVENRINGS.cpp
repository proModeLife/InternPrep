#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,n,x;
	cin>>t;
	while(t--){
	    cin>>n>>x;
	    if (n*x>=10000 and n*x <=99999)
	        cout<<"YES"<<endl;
	   else cout<<"NO"<<endl;
	}
	return 0;
}
