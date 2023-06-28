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
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({2*a,1});
        arr.push_back({2*b+1,-1});
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    int curr=0;
    for (auto it: arr){
        curr+=it.second;
        ans=max(ans,curr);
    }
    cout<<ans<<endl;
      
    return 0;
}
