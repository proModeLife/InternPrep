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

struct DSU
{
    vector<int> parents;
    vector<int> ranks;
    public:
    int components;
    int largest;
    DSU(int n)
    {
        parents.resize(n);
        for(int i=0;i<n;i++)
            parents[i]=i;
        ranks.resize(n);
        fill(ranks.begin(),ranks.end(),1);
        components=n;
        largest=1;
    }

    int root(int i)
    {
        while(i!=parents[i])i=parents[i];
        return i;
    }

    void join(int a, int b)
    {
        a=root(a);
        b=root(b);
        if(a==b)return;
        else
        {
            if(ranks[a]>ranks[b] || ranks[a]==ranks[b] && a<b)
            {
                parents[b]=a;
                ranks[a]+=ranks[b];
                components--;
                largest=max(largest,ranks[a]);
            }
            else 
            {
                parents[a]=b;
                ranks[b]+=ranks[a];
                components--;
                largest=max(largest,ranks[b]);
            }
        }
        return;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your code here
    int n,m;
    cin>>n>>m;
    DSU dsu= DSU(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        dsu.join(a, b);
        cout<<dsu.components<<" "<<dsu.largest<<endl;
    }
	return 0;
}
