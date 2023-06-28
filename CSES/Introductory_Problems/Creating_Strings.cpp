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
    string s;
    cin>>s;
    vector<string> ans;
    sort(s.begin(),s.end());
    do{
      ans.push_back(s);
    }while (next_permutation(s.begin(),s.end()));
    cout<<ans.size()<<endl;
    for(auto i: ans)cout<<i<<endl;

    return 0;
}
