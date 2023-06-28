#include <array>
#include <climits>
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
    vector<vector<int> > vec;
    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vec.push_back({a,b,i});
    }
    vector<bool> ans1(n,false);
    vector<bool> ans2(n,false);

    sort(vec.begin(),vec.end());

    int minend=INT_MAX,maxend=INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        if(vec[i][1]>=minend)ans1[vec[i][2]]=true;
        minend=min(minend,vec[i][1]);
    }

    for(int i=0;i<n;i++)
    {
        if(vec[i][1]<=maxend)ans2[vec[i][2]]=true;
        maxend=max(maxend,vec[i][1]);
    }
    for(int i=0;i<n;i++)cout<<ans1[i]<<" ";
        cout<<endl;
    for(int i=0;i<n;i++)cout<<ans2[i]<<" ";
        cout<<endl;

   	return 0;
}
