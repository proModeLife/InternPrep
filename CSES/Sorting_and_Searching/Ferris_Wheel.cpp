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
    int n,x;
    cin>>n>>x;
    long long p[n];
    for(int i=0;i<n;i++)cin>>p[i];
    sort(p,p+n);
    long long ans=0;
    int l=0,r=n-1;
    while(l<r){
        if(p[l]+p[r]>x){
            r--;
            ans++;
        }else{
            ans++;
            l++;
            r--;
        }
    }
    ans+=(l==r);
    cout<<ans<<endl;
	return 0;
}
