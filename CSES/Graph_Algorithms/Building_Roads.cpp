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
const int maxN=1e5+1;
bool visited[maxN];

void dfs(int i,vector< vector<int> > &adj)
{
    visited[i]=true;
    for(auto j: adj[i])
    {
        if(!visited[j])dfs(j,adj);
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your code here
    int n,m;
    cin>>n>>m;
    vector< vector<int> > adj (n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj);
            ans.push_back(i+1);
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=0;i<ans.size()-1;i++)cout<<ans[i]<< " "<< ans[i+1]<<endl;

	return 0;
}
