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

const int mxN=2e5;
int n,q;
int t[30][mxN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your code here
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>t[0][i];t[0][i]--;
    }
    for(int i=1;i<30;i++)
        for(int j=0;j<n;j++)
            t[i][j]=t[i-1][t[i-1][j]];
    while(q--)
    {
        int a,b;
        cin>>a>>b;--a;
        for(int i=0;i<30;i++)
            if(b&(1<<i))
                a=t[i][a];
        cout<<a+1<<endl;
    }
    

	return 0;
}
