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
    cin>>x>>n;
    set<int> places;
    places.insert(0);
    places.insert(x);
    multiset<int> lengths;
    lengths.insert(x);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        auto it=places.upper_bound(t);
        int high=*it;
        it--;
        int low=*it;
        lengths.erase(lengths.find(high-low));
        places.insert(t);
        lengths.insert(t-low);
        lengths.insert(high-t);
        auto itr=lengths.end();
        itr--;
        cout<<*itr<<" ";
    }
    cout<<endl;
	return 0;
}
