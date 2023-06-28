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

const int mxN =2e5+1;
stack<int> stk;
vector<int> adj[mxN],adjT[mxN];
int group[mxN];
int groupNumber;
bool visited[mxN];
int n,m;

void dfs1(int u)
{
    visited[u]=true;
    for(int v: adj[u])
    {
        if(!visited[v])
            dfs1(v);
    }
    stk.push(u);
}

void dfs2(int u)
{
    visited[u]=true;
    group[u]=groupNumber;
    for(int v: adjT[u])
    {
        if(!visited[v])
            dfs2(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code here
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        char type1, type2;
        int x, y;

        cin >> type1 >> x >> type2 >> y;
        x--;y--;
        x*=2;y*=2;
        if (type1 == '-') x ^=1;
        if (type2 == '-') y ^=1;
        adj[x^1].push_back(y);
        adj[y^1].push_back(x);
        adjT[y].push_back(x^1);
        adjT[x].push_back(y^1);
    }
    for(int i=0;i<2*m;i++)
        if(!visited[i])
            dfs1(i);
    groupNumber=1;
    memset(group, 0, sizeof(group));
    memset(visited, false, sizeof(visited));
    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();
        if (!visited[u])
        {
            dfs2(u);
            groupNumber++;
        }
    }
    vector<char>  ans;
    for(int i=0;i<2*m;i+=2)
    {
        //cout<<group[i]<< " " << group[i+1]<< endl;
        if(group[i]<group[i+1])ans.push_back('-');
        if(group[i]>group[i+1])ans.push_back('+');
        if(group[i]==group[i^1])
        {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    for(char c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}
