#include <array>
#include <iostream>
#include <utility>
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
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).begin() , (x).end()

using namespace std;
const int maxN = 1e3;
char mat[maxN][maxN];
bool vis[maxN][maxN];
pair<int ,int > source;
int  n, m ;

int dx[4] = {-1 , 0 , 1 , 0};
int dy[4] = {0, 1, 0 , -1 };
pair<int ,int > dest;
int parent[maxN][maxN];

bool isok(int xx , int yy)
{
    if( xx >=0 && yy >=0 && xx <n && yy < m && mat[xx][yy] != '#' && !vis[xx][yy])
    {
        return true;
    }
    return false;
}

void bfs()
{
    queue<pair<int, int> > q;
    q.push({source.first,source.second}); 
    vis[source.first][source.second] = true;
    while(!q.empty())
    {
        auto dd = q.front();
        q.pop();
        if(dd.first==dest.first&&dd.second==dest.second){
            cout<<"YES"<<endl;
            vector<char> pos;
            while(dd != source)
            {
                int x = dd.first, y = dd.second;
                int px = parent[x][y] / m, py = parent[x][y] % m;
                if(py == y+1) pos.push_back('L');
                else if(py == y-1) pos.push_back('R');
                else if(px == x+1) pos.push_back('U');
                else if(px == x-1) pos.push_back('D');
                dd = {px, py};
            }
            reverse(pos.begin(), pos.end());
            cout<<pos.size()<<endl;
            for(char c : pos) cout<<c;
            cout<<endl;
            return;
        }
        for(int i =0; i<4; ++i)
        {
            int xx = dd.first + dx[i], yy = dd.second + dy[i];
            if(isok(xx, yy))
            {
                parent[xx][yy] = dd.first * m + dd.second;
                vis[xx][yy] = true;
                q.push({xx, yy});
            }
        }
    }
    cout<<"NO"<<endl;
}


int32_t main(){
    IOS;
    cin >>n >>m;
    for(int i =0; i<n; ++i){
        for(int j =0; j<m; ++j){
            cin >> mat[i][j];
        }
    }
    memset(vis , false , sizeof(vis));
    for(int i =0; i<n; ++i){
        for(int j =0; j<m; ++j){
            if( mat[i][j] == 'A')
            {
                source = {i , j};
            }
            if(mat[i][j] == 'B')
            {
                dest = {i , j};
            }
        }
    }
    bfs();

    return 0;
}
