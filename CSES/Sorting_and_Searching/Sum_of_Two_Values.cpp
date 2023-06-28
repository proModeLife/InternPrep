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
    int n,x;
    cin>>n>>x;
    set<array<int, 2>> s;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if (t<x){
            auto it = s.lower_bound({x-t,0});
            if (it!=s.end()&& (*it)[0]==x-t){
                cout<< (*it)[1]+1<<" "<< i+1<< endl;
                return 0;
            }else{
                s.insert({t,i});
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
