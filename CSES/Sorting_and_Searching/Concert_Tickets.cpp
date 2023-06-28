#include <array>
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
    int n,m;
    cin>>n>>m;
    set<array<int, 2>>s;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        s.insert({t,i});
    }
    
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        auto it=s.lower_bound({t+1,0});
        if (it==s.begin())
            cout<<-1<<endl;
        else{
            it--;
            cout<<(*it)[0]<<endl;
            s.erase(it);
        }
    }


	return 0;
}
