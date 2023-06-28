#include <iostream>
#include <utility>
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
    vector<pair<int, int>> vec;
    for (int i=0; i<n; i++) {
        int a,b;
        cin>>a>>b;
        vec.push_back({b,a});
    }
    sort(vec.begin(),vec.end());
    int i=0;
    int ans=0;
    while(i<n){
        int j=i;
        ans++;
        while(j<n && vec[j].second<vec[i].first)j++;
        i=j;
    }
    cout<<ans<<endl;

	return 0;
}
