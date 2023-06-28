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
    long long p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    sort(p,p+n);
    long long x=p[n/2];
    long long ans=0;
    for(int i=0;i<n;i++)
        ans+=abs(p[i]-x);
    std::cout << ans << std::endl;
	return 0;
}
