
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

const int maxN = 102;
int arr[maxN], pre[maxN];
bool used[maxN];
int n;
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> n >> k;
        memset(used,false,sizeof(used));
        int l = INT_MAX, r = 0;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (k == n)
        {
            cout << 0 << endl;
        }
        else
        {
            int ans=0;
            vector<int>vec(n-1);
            for(int i=1;i<n;i++)
                vec[i-1]=abs(arr[i]-arr[i-1]);
            sort(vec.begin(),vec.end());
            for(int i=0;i+k<n;i++)
                ans+=vec[i];
            cout << ans << endl;
        }
    }

    return 0;
}

