#include <array>
#include <climits>
#include <iostream>
#include <ostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
const int maxN=1000,maxM=1000;
char parent[maxN][maxM];
int grid[maxN][maxM];
pair<int,int> start; 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    queue<array<int, 3>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char x;
            cin>>x;
            if(x=='A')
            {
                start={i,j};
                parent[i][j]='S';
                grid[i][j]=INT_MAX;
            }
            else if (x=='M')
            {
                q.push({i,j,0});
                grid[i][j]=0;
            }
            else if (x=='.')
            {
                grid[i][j]=INT_MAX;
            }
            else grid[i][j]=0;
        }
    }
    while(!q.empty())
    {
        int i,j,c;
        auto it = q.front(); q.pop();
        i=it[0],j=it[1],c=it[2];
        if (grid[i][j]!=c)continue;
        if (i>0 && grid[i-1][j] > c+1)
        {
            grid[i-1][j]=c+1;
            q.push({i-1,j,c+1});
        }
        if (j>0 && grid[i][j-1] > c+1)
        {
            grid[i][j-1]=c+1;
            q.push({i,j-1,c+1});
        }
        if (i+1<n && grid[i+1][j] > c+1)
        {
            grid[i+1][j]=c+1;
            q.push({i+1,j,c+1});
        }
        if (j+1<m && grid[i][j+1] > c+1)
        {
            grid[i][j+1]=c+1;
            q.push({i,j+1,c+1});
        }
    }
    q.push({start.first,start.second,0});
   // for(int i=0;i<n;i++)
   // {
   //     for(int j=0;j<m;j++){
   //         cout<<grid[i][j]<<" ";
   //     }
   //     cout<<endl;
   // }cout<<endl;

    while(!q.empty())
    {
        auto it = q.front();q.pop();
        int i=it[0],j=it[1],c=it[2];
        //cout<<i<<" "<<j<<" "<<c<<endl;
        if(i==0||j==0||i==n-1||j==m-1)
        {
            vector<char> ans;
            while(parent[i][j]!='S')
            {
                ans.push_back(parent[i][j]);
                char x=parent[i][j];
                i=i-(x=='D')+(x=='U');
                j=j-(x=='R')+(x=='L');
            }
            cout<<"YES"<<endl;
            cout<<ans.size()<<endl;
            
            for(int i=ans.size()-1;i>=0;i--)
            {
                cout<<ans[i];
            }
            cout<<endl;
            return 0;
        }
        if (i>0 && grid[i-1][j] > c+1 && !parent[i-1][j])
        {
            parent[i-1][j]='U';
            q.push({i-1,j,c+1});
        }
        if (j>0 && grid[i][j-1] > c+1 && !parent[i][j-1])
        {
            parent[i][j-1]='L';
            q.push({i,j-1,c+1});
        }
        if (i+1<n && grid[i+1][j] > c+1 && !parent[i+1][j])
        {
            parent[i+1][j]='D';
            q.push({i+1,j,c+1});
        }
        if (j+1<m && grid[i][j+1] > c+1 && !parent[i][j+1])
        {
            parent[i][j+1]='R';
            q.push({i,j+1,c+1});
        }


    }

    cout<<"NO"<<endl;
    return 0;
}
