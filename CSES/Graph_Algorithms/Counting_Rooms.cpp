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
vector<string> grid(1000);
int n,m;
void dfs(int i,int j){
    if(i<0 || j<0 || i==n || j==m || grid[i][j]!='.')return;
    grid[i][j]='#';
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
} 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your code here
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}
